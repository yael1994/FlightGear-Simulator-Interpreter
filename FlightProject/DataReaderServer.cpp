//
// Created by daniel on 12/14/18.
//

#include <sstream>
#include <algorithm>
#include "DataReaderServer.h"
#include "NameToPathTable.h"

//NameToPathTable* NameToPathTable::_instance = NULL;
//SymbolTable* SymbolTable::_instance = NULL;

void DataReaderServer::operator()(int portno, int hz) {
    this->symbolTable = SymbolTable::getInstance();
    int sockfd;
    int newsockfd;
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;
    int  n;

/* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    cout<<"S"<<endl;

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");

    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while(1){
        /* If connection is established then start communicating */
        cout<<"c"<<endl;
        bzero(buffer, 256);
        read(newsockfd, buffer,255);
        split();

        if (n < 0) {
            perror("ERROR reading from socket");

        }
        sleep(1 / hz);

        cout << buffer << endl;
    }
//    FILE* fin;
//    fin = fopen("try.txt","r");
//
//    for(int i =0; i< 256;i++) {
//        fread(this->buffer, 1, 256, fin);
//        split();
//    }

}
void DataReaderServer::split() {
  for(int i = 0; i< strlen(buffer); i++){
      string buf;
      while(buffer[i] != ',') {
          buf += buffer[i];
          i++;
      }
      double num = stod(buf);
      valueFromSimu.push_back(num);
      i++;
  }
  setArgs();
}

void DataReaderServer::setArgs() {
    NameToPathTable* pathTable = NameToPathTable::getInstance();
    for(auto key : this->symbolTable->getSymbolTable()){
        string name = key.first;
        if(pathTable->getPath(name) != "" ) {
            string path = pathTable->getPath(name);
            int i = pathTable->getIndex(path);
            //fix the 23!!!!!!!!!!!!!
            if( i< 23){
            this->symbolTable->setDoubleValue(name, valueFromSimu[i]);
            cout << name << " " << valueFromSimu[i] << endl;
                }
        }
    }
}


