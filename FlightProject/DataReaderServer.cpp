
#include <sstream>
#include <algorithm>
#include <thread>
#include "DataReaderServer.h"
#include "NameToPathTable.h"
#define  SEPERATE ','
//NameToPathTable* NameToPathTable::_instance = NULL;
//SymbolTable* SymbolTable::_instance = NULL;

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
            int n = read(newsockfd, buffer, 1023);
            if (n < 0) {
                perror("Error: reading from socket");
            }
            sleep(1 / 10);
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

void DataReaderServer::setArgs() {

    for(auto key : this->symbolTable->getSymbolTable()){
        string name = key.first;
        if(pathTable->countPath(key.first)) {
            string path = pathTable->getPath(name);
            if(pathTable->countPathToIndex(path)){
            int i = pathTable->getIndex(path);
            this->symbolTable->setDoubleValue(name, valueFromSimu[i],0);
            cout << name << " " << valueFromSimu[i] << endl;
            }
        }
    }
    valueFromSimu.clear();
}



