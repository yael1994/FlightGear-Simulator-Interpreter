//
// Created by daniel on 12/14/18.
//

#include <thread>
#include "ConnectCommand.h"
#include "SendMesagge.h"
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
 * Constructor by IDE 
 * @param iterator 
 */
ConnectCommand::ConnectCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

        
        
void ConnectCommand::execute() {
    this->next();
    string ip = this->getString();
    this->next();
    int port =(int) toDouble->calculateExp(convertToString());
    this->next();
    openClient(ip,port);

}





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
/**
 * 
 * this method open the socket for the client and whit to connection 
 * if there is a condition its open a thread for the message sendig 
 *
 * @param ip 
 * @param port 
 */
void ConnectCommand::openClient(string &ip, int port) {
    int sockfd;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }
        //get host
        server = gethostbyname(ip.c_str());

        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port);
        //connect to an other socket of the server
        int c = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        //if the socket is wrong close it and continue to try
        if(c < 0){
         cout<< "no socket of client"<<endl;
        }
        //if the connection is good break the loop

    /* Now connect to the server */
    cout<<"open thread for client"<<endl;
    //open thread for the message sending of the client
    thread t1(SendMesagge::sendMsg,sockfd);
    t1.detach();
}
