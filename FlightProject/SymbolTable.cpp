//
// Created by daniel on 12/17/18.
//

#include <thread>
#include "SymbolTable.h"
/**
 * this method set the args of the value
 * if the flag is on it means that we came from the setCommand and we want to update the plane simiulator
 * @param key
 * @param num
 * @param flag true from set false from others
 */
void SymbolTable::setDoubleValue(string &key, double num, bool flag) {
    lock_guard<std::mutex> lock(myLock);
    this->symbolTable[key] = num;
}