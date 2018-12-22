//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stack>

#include <mutex>

#define XML "generic_small.xml"
using namespace std;

class SymbolTable {
    static SymbolTable* _instance;
    mutex myLock;
    map<string, double> symbolTable;
    stack<string> updates;

    SymbolTable()= default;

public:
    static SymbolTable* getInstance(){
        if(_instance == NULL){
            _instance = new SymbolTable();
        }
        return _instance;
    }

    void setDoubleValue(string &key, double num,bool flag){
        myLock.lock();
        this->symbolTable[key] = num;
        if(flag) {
            updates.push(key);
        }
        myLock.unlock();

    }

    stack<string> &getStackUpdates()  {
        return updates;
    }


    const map<string, double> &getSymbolTable() const {
        return symbolTable;
    }

    const double getValue(string key){
        return this->symbolTable.find(key)->second;
    }





};



#endif //UNTITLED4_SYMBOLETABLE_H
