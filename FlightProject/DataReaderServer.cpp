//
// Created by daniel on 12/14/18.
//

#include <sstream>
#include <algorithm>
#include <thread>
#include "DataReaderServer.h"
#include "NameToPathTable.h"

//NameToPathTable* NameToPathTable::_instance = NULL;
//SymbolTable* SymbolTable::_instance = NULL;

void DataReaderServer::operator()(int portno, int hz) {
    this->symbolTable = SymbolTable::getInstance();
    int sockfd;

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
    newsockfd = -1;
    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
//    cout<<"c"<<endl;
//    auto f = [this](){
//        while(true){
//         //   cout<<"c"<<endl;
//            bzero(buffer,1024);
//            int n =read(newsockfd,buffer,1023);
//            if(n<0){
//             //   perror("Error: reading from socket");
//            }else{
//                split();
//            }
//            sleep(1/30);
//            split();
//
//        }
//    };
//    if(newsockfd > 0){
//        thread t1(f);
//        t1.detach();
//    }
    while(true){
           cout<<"c"<<endl;
        bzero(buffer,1024);
        int n =read(newsockfd,buffer,1023);
        if(n<0){
             perror("Error: reading from socket");
        }
        sleep(1/10);
        split();

    }


}
void DataReaderServer::split() {
  for(int i = 0; i< strlen(buffer); i++){
      string buf;

      while(buffer[i] != ',' || i < strlen(buffer)) {
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



