//
// Created by daniel on 12/16/18.
//

#include "setCommand.h"
#include "NameToPathTable.h"
#include "ClientConnect.h"
#include "SymbolTable.h"

setCommand::setCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

void setCommand::execute() {
    NameToPathTable* nameToPath = NameToPathTable::getInstance();
    SymbolTable* symbolTable = SymbolTable::getInstance();
    string name  = this->getString();
    string path = nameToPath->getPath(name);
    this->next();
    this->next();
    string value = this->getString();
    path.erase(0,1);
    string msg = "set "+ path+ " "+ value+"\r\n";
    ClientConnect* c = ClientConnect::getInstance();
    c->sendMessage(msg);
    double v = toDouble->calculateExp(this->getString());
    symbolTable->setDoubleValue(name,v);

    this->next();
}
