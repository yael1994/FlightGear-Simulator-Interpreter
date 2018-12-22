//
// Created by daniel on 12/14/18.
//

#include "PrintCommand.h"
#include "SymbolTable.h"


void PrintCommand::execute() {
SymbolTable* p=SymbolTable::getInstance();
this->next();
while (this->getString()!="\n"){
    if(this->getString()=="\""){
       this->next();
       while (getString()!="\"") {
           cout << this->getString();
           this->next();
       }
    } else {
        p->getValue(this->getString());
    }
}
}

PrintCommand::PrintCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}
