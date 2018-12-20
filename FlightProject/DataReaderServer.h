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

#include <string.h>

#include <sys/socket.h>
#include <iostream>
#include "SymbolTable.h"


using namespace std;
class DataReaderServer {
//    SymbolTable* symbolTable;
public:

    void operator()(int portno, int hz);
};


#endif //UNTITLED4_DATAREADERSERVER_H
