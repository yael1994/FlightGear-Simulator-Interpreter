
#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <mutex>
#include "NameToPathTable.h"

using namespace std;


class SymbolTable {
    static SymbolTable* _instance;
    unordered_map<string, double> symbolTable;
    queue<string> updates;
    mutex myLock;


    SymbolTable()= default;


public:
    static SymbolTable* getInstance(){
        if(_instance == NULL){
            _instance = new SymbolTable();
        }
        return _instance;
    }

    void setDoubleValue(string &key, double num,bool flag);


    const unordered_map<string, double> &getSymbolTable() const {

        return symbolTable;
    }

    const double getValue(string key){
        lock_guard<std::mutex> lock(myLock);
        double value = this->symbolTable.find(key)->second;
        return value;

    }
    ~SymbolTable(){
        delete _instance;
    }


};


#endif //UNTITLED4_SYMBOLETABLE_H
