//
// Created by daniel on 12/15/18.
//

#include "SendMesagge.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>

#include <string.h>
#include "Command.h"

int sock;

/**
 * the method loop the queue of the updates ands if it's not emtpy
 * send the message to the correct socket and pop the msg out
 * @param socket
 */

void SendMesagge::sendMsg(string msg) {
    lock_guard<std::mutex> lock(thisLock);
    int n = ::send(sock, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
    cout<< msg<< endl;
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
                char buffer[256];
                /* Now read server response */
                bzero(buffer, 256);
                n = read(sock, buffer, 255);

                printf("%s\n", buffer);
}


void SendMesagge::openClient(string ip, int port) {
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
    sock = sockfd;
    //if the socket is wrong close it and continue to try
    if (c < 0) {
        cout << "no socket of client" << endl;
    }
    //if the connection is good break the loop


}



