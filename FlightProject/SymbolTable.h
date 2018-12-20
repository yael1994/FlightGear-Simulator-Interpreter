//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class SymbolTable {
    static SymbolTable* _instance;
    typedef struct var{
        string name;
        string path;
        string index;
    };
    map<var, double> symbolTable;
    SymbolTable(){}
public:
    static SymbolTable* getInstance(){
        if(_instance == NULL){
            _instance = new SymbolTable();
        }
        return _instance;
    }

//    void setValue(string &key, double num){
//        this->symbolTable[key] = num;
//    }
//
//    const map<string, double> &getSymbolTable() const {
//        return symbolTable;
//    }

};



#endif //UNTITLED4_SYMBOLETABLE_H
