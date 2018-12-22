//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define XML "generic_small.xml"
using namespace std;

class SymbolTable {
    static SymbolTable* _instance;

    map<string, double> symbolTable;

    SymbolTable()= default;

public:
    static SymbolTable* getInstance(){
        if(_instance == NULL){
            _instance = new SymbolTable();
        }
        return _instance;
    }

    void setDoubleValue(string &key, double num){
        this->symbolTable[key] = num;

    }

    const map<string, double> &getSymbolTable() const {
        return symbolTable;
    }

    const double getValue(string key){
        return this->symbolTable.find(key)->second;
    }





};



#endif //UNTITLED4_SYMBOLETABLE_H
