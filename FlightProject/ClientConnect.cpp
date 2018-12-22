//
// Created by daniel on 12/15/18.
//

#include "ClientConnect.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>

#include <thread>
#include <string.h>




void ClientConnect::openClient(string ip, int port) {

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

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
    flag = false;
    while(true) {
        int c = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        /* Now connect to the server */
        if (c == 0) {
           flag = true;
           break;
        }
    }
    cout << "client connect" << endl;
    /* Now ask for a message from the user, this message
       * will be read by server
    */
//
//    printf("Please enter the message: ");
//    bzero(buffer,256);
//    fgets(buffer,255,stdin)

//        while (true) {
//            string i = "-1";
//           // msg = "set controls/flight/rudder "+i+"\r\n";
//          //  n = send(sockfd, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
//            /* Send message to the server */
//            //   n = send(sockfd, setMsg.c_str(), strlen(setMsg.c_str()), 0);
//            // n = write(sockfd, buffer, strlen(buffer));
//           // sleep(5);
//          //  i = "1";
//
////            if (n < 0) {
////                perror("ERROR writing to socket");
////                exit(1);
////            }
//
//
//            /* Now read server response */
//            bzero(buffer, 256);
//           n = read(sockfd, buffer, 255);
//
//            if (n < 0) {
//
//              //  perror("ERROR reading from socket");
//                //exit(1);
//            }
//
//            printf("%s\n", buffer);
//        }
    }


void ClientConnect::sendMessage(string msg) {
    //this->msg = msg;
    if(flag) {
        n = send(sockfd, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        char buffer[256];
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

        if (n < 0) {

            //  perror("ERROR reading from socket");
            //exit(1);
        }

        printf("%s\n", buffer);
    }

}
