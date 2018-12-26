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


void SendMesagge::sendMsg(int socket) {
    NameToPathTable *path = NameToPathTable::getInstance();
    SymbolTable *symbolTable = SymbolTable::getInstance();
    while (true) {
       if(!symbolTable->isQueueEmpty()){
                string msg = symbolTable->getQueueUpdatesFront();
                     symbolTable->queuePop();
                int n = send(socket, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
                
                cout<<msg<<endl;
                
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
                char buffer[256];
                /* Now read server response */
                bzero(buffer, 256);
                n = read(socket, buffer, 255);

                printf("%s\n", buffer);
            }
        }
    }


