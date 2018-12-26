//
// Created by daniel on 12/14/18.
//

#include <sstream>
#include <algorithm>
#include <thread>
#include "DataReaderServer.h"
#include "NameToPathTable.h"
#define  SEPERATE ','

/**
 * overload operator () to use thred calling
 * @param newsockfd the socket that opended
 * @param hz
 */
void DataReaderServer::operator()(int newsockfd, int hz) {
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
            sleep(1 / hz);
            split();
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
            cout << name << " " << valueFromSimu[i] << endl;
            }
        }
    }
    valueFromSimu.clear();
}



