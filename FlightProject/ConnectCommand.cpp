//
// Created by daniel on 12/14/18.
//

#include <thread>
#include "ConnectCommand.h"
#include "ClientConnect.h"
#include "CreateExp.h"
#include "ExpressionSingleTone.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>


#include <string.h>

ExpressionSingleTone* ExpressionSingleTone::_instance = NULL;

/**
 * this
 */
void ConnectCommand::execute() {
    this->next();
    string ip = this->getString();
    this->next();
    int port =(int) toDouble->calculateExp(convertToString());
    this->next();
    int sockfd;

//    thread t1(f,ip,port);
//    t1.detach();
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
while(true) {
    /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    int c = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if(c < 0){
        close(sockfd);
        continue;
    }
    break;

}
    /* Now connect to the server */
        cout<<"open thread for client"<<endl;
    thread t1(ClientConnect::sendMsg,sockfd);
    t1.detach();
}



ConnectCommand::ConnectCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

string ConnectCommand::convertToString() {
    string ans;
    while (this->getString()!="\n") {
        if(this->getString()==","){
            this->next();
            continue;
        }
        ans += this->getString();
        this->next();
    }
    return ans;
}
