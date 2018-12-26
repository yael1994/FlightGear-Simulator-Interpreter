
#include "setCommand.h"
#include "NameToPathTable.h"
#include "SendMesagge.h"
#include "SymbolTable.h"
#include "Utils.h"

setCommand::setCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

void setCommand::execute() {
    NameToPathTable* paths = NameToPathTable::getInstance();
    SymbolTable* symbolTable = SymbolTable::getInstance();
    string name  = this->getString();
    this->next();//find the "="
    this->next();//over the "="
    string str;
    while(this->getString()!="\n"){
        if(!Utils::isNumber(this->getString())&&!Utils::isOperator(this->getString())
           &&this->getString()!="("&& this->getString()!=")"){
            str+=to_string(symbolTable->getValue(this->getString()));
            this->next();
            continue;
        }
        str+=this->getString();
        this->next();
    }

    double v = toDouble->calculateExp(str);
    symbolTable->setDoubleValue(name,v,1);

    this->next();
}