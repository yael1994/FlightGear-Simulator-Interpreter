//
// Created by daniel on 12/14/18.
//

#include <regex>
#include "PrintCommand.h"
#include "SymbolTable.h"


using namespace std;


void PrintCommand::execute() {
SymbolTable* p=SymbolTable::getInstance();
this->next();

while (this->getString()!="\n"){
    if(p->getSymbolTable().count(this->getString())>0){
        cout<< p->getValue(this->getString());
        this->next();
    }else{

        cout<<this->getString();
        this->next();
    }
}
 cout<<endl;
 this->next();
}

PrintCommand::PrintCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}
