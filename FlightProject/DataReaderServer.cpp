//
// Created by daniel on 12/14/18.
//

#include <sstream>
#include "DataReaderServer.h"



void DataReaderServer::operator()(int portno, int hz) {
//    this->symbolTable = SymbolTable::getInstance();
    int sockfd;
    int newsockfd;
    int clilen;
    char buffer[256];
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

        if (n < 0) {
            perror("ERROR reading from socket");

        }
        sleep(1 / hz);

        cout << buffer << endl;
    }
}


