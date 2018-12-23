//
// Created by daniel on 12/15/18.
//


#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "SymbolTable.h"
#include "NameToPathTable.h"

#define XML "generic_small.xml"
using namespace std;

class ClientConnect {
    static ClientConnect* _instance;
    bool flag;
    int sockfd, n;
    SymbolTable* symbolTable = SymbolTable::getInstance();
    NameToPathTable* paths  = NameToPathTable::getInstance();
    string msg;
    ClientConnect()= default;

public:
    static ClientConnect* getInstance(){
        if(_instance == NULL){
            _instance = new ClientConnect();
        }
        return _instance;
    }

    void openClient(string  ip , int port);
    void sendMessage(string msg);




};
