
#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>

#include <mutex>
#include "NameToPathTable.h"

#define XML "generic_small.xml"
using namespace std;

class SymbolTable {
    static SymbolTable* _instance;
    //NameToPathTable* paths{};
    mutex myLock;
    map<string, double> symbolTable;
    queue<string> updates;

    SymbolTable()= default;

public:
    static SymbolTable* getInstance(){
        if(_instance == NULL){
            _instance = new SymbolTable();
        }
        return _instance;
    }

    void setDoubleValue(string &key, double num,bool flag) {
        myLock.lock();
        this->symbolTable[key] = num;
                if (flag) {
           NameToPathTable* paths = NameToPathTable::getInstance();
            string name = key;
            if (paths->countPath(name)) {
                string path = paths->getPath(name);
                path.erase(0, 1);
                string value = to_string(this->symbolTable.find(key)->second);
                string msg = "set " + path + " " + value + "\r\n";
                updates.push(msg);
            }

        }
        myLock.unlock();
    }

    string getQueueUpdatesFront()  {
        string front= this->updates.front();
        return front;
    }
    void queuePop(){
        this->updates.pop();
    }
    bool isQueueEmpty(){
        return this->updates.empty();
    }


    const map<string, double> &getSymbolTable() const {
        return symbolTable;
    }

    const double getValue(string key){
        myLock.lock();
        double value = this->symbolTable.find(key)->second;
        myLock.unlock();
        return value;

    }
};

//        if (flag) {
//            paths = NameToPathTable::getInstance();
//            string name = key;
//            if (paths->countPath(name)) {
//                string path = paths->getPath(name);
//                path.erase(0, 1);
//                string value = to_string(this->symbolTable.find(key)->second);
//                string msg = "set " + path + " " + value + "\r\n";
//                updates.push(msg);
//            }
//
//        }

#endif //UNTITLED4_SYMBOLETABLE_H
