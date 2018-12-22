//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_DATAREADERSERVER_H
#define UNTITLED4_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include<vector>
#include <string.h>

#include <sys/socket.h>
#include <iostream>
#include "SymbolTable.h"


using namespace std;
class DataReaderServer {
    SymbolTable* symbolTable;
    char buffer[1042];
    vector<double> valueFromSimu;
    int newsockfd;

public:
    DataReaderServer(){}
    void operator()(int portno, int hz);
    void split();

    void setArgs();
    void readFromSocket();
};


#endif //UNTITLED4_DATAREADERSERVER_H
