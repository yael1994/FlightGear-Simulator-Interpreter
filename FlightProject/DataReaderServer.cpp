
#include <sstream>
#include <algorithm>
#include <thread>
#include "DataReaderServer.h"
#include "NameToPathTable.h"
#define  SEPERATE ','

#include "Command.h"

/**
 * overload operator () to use thred calling
 * @param newsockfd the socket that opended
 * @param hz
 */
void DataReaderServer::operator()(int newsockfd, int hz) {
    this->newsockfd = newsockfd;
    this->symbolTable = SymbolTable::getInstance();
    this->pathTable =  NameToPathTable::getInstance();
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while(true){
        if(newsockfd >= 0) {
            bzero(buffer, 1024);
            //read from socket
            int n = read(newsockfd, buffer, 1023);
            if (n < 0) {
                perror("Error: reading from socket");
            }
            split();
            sleep(hz/1000);


        }

    }


}

/**
 * this function splits the the input vector from the server by ","
 */
void DataReaderServer::split() {
    int i = 0;
    int j = 0;
    this->buffer;
    while(j < pathTable->getPathSize()){
      string buf;
      while(buffer[i] != SEPERATE && buffer[i] != '\n') {
          buf += buffer[i];
          i++;
      }
      i++;
      double num = stod(buf);
      valueFromSimu.push_back(num);
      j++;
  }
  setArgs();
}

/**
 * this function runs the symbol table and check if there is a path to update
 * and if there is-> update from the vector that received from the server
 */
void DataReaderServer::setArgs() {
    lock_guard<std::mutex> lock(thisLock);
    for(auto key : this->symbolTable->getSymbolTable()){
        string name = key.first;

        if(pathTable->countPath(key.first)) {
            //if there is a path get it
            string path = pathTable->getPath(name);
            //if the path have index set an update
            if(pathTable->countPathToIndex(path)){
            int i = pathTable->getIndex(path);
            //set the value of the relevent var by the index
            this->symbolTable->setDoubleValue(name, valueFromSimu[i],0);

            //cout << name << " " << valueFromSimu[i] << endl;

            }
        }
    }
    valueFromSimu.clear();

}



