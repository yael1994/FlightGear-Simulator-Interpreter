//
// Created by daniel on 12/17/18.
//

#include "SymbolTable.h"

void SymbolTable::setDoubleValue(string &key, double num, bool flag) {


    myLock.lock();
    this->symbolTable[key] = num;
    if (flag) {
        NameToPathTable *paths = NameToPathTable::getInstance();
        string name = key;
        if (paths->countPath(name)) {
            string path = paths->getPath(name);
            path.erase(0, 1);
            string value = to_string(num);
            string msg = "set " + path + " " + value + "\r\n";
            updates.push(msg);
        }

    }
    myLock.unlock();
}