
#include "ClientConnect.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>

#include <string.h>



//void ClientConnect::setMessage(string msg) {
//    myLock.lock();
//    this->msg = msg;
//    myLock.unlock();
//}
//
//void ClientConnect::sendToSocket(int socket) {
//    while(true) {
//        if (!msg.empty()) {
//            myLock.lock();
//            n = send(socket, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
//            myLock.unlock();
//            if(n <0 ){
//                cout<<"client error"<<endl;
//            }
//            msg.clear();
//        }
//    }
//
//}
void ClientConnect::sendMsg(int socket) {
    NameToPathTable *path = NameToPathTable::getInstance();
    SymbolTable *symbolTable = SymbolTable::getInstance();
//
//    struct sockaddr_in serv_addr;
//    struct hostent *server;
//
//    char buffer[256];
//
//    /* Create a socket point */
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//
//    if (sockfd < 0) {
//        perror("ERROR opening socket");
//        exit(1);
//    }
//
//    server = gethostbyname(ip.c_str());
//
//    if (server == NULL) {
//        fprintf(stderr, "ERROR, no such host\n");
//        exit(0);
//    }
//
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//    serv_addr.sin_family = AF_INET;
//    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
//    serv_addr.sin_port = htons(port);
//    flag = false;
//
//    int c = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
//    /* Now connect to the server */
//
//    cout << "client connect" << endl;
//    /* Now ask for a message from the user, this message
//       * will be read by server
//    */


    while (true) {

        for (auto key :  symbolTable->getSymbolTable()) {
            if (path->countPath(key.first)) {
                string pathN = path->getPath(key.first);
                pathN.erase(0,1);
                string value = to_string(symbolTable->getValue(key.first));
                string msg = "set " + pathN + " " + value + "\r\n";

                int n = send(socket, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);



                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }

                char buffer[256];
                /* Now read server response */
                bzero(buffer, 256);
                n = read(socket, buffer, 255);

                if (n < 0) {

                    //  perror("ERROR reading from socket");
                    //exit(1);
                }

                printf("%s\n", buffer);
            }
        }
    }
}


