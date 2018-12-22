//
// Created by daniel on 12/14/18.
//

#include "DefineVarCommand.h"
#include "NameToPathTable.h"
#include "SymbolTable.h"

NameToPathTable* NameToPathTable::_instance = NULL;

DefineVarCommand::DefineVarCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

void DefineVarCommand::execute() {
    NameToPathTable* table =NameToPathTable::getInstance();
    SymbolTable* symbolTable = SymbolTable::getInstance();
    this->next();
    string name = this->getString(); //get name
    this->next(); //go to "="
    this->next();//avoid "="
    if(this->getString()== "bind"){
        this->next();
        if(this->getString()[0] =='/'){
            table->setPathValue(name,this->getString());
          symbolTable->setDoubleValue(name,0);  }
          else {
            //bind to other var that already bind, find the path of him and put it
            table->setPathValue(name, table->getPath(this->getString()));
            symbolTable->setDoubleValue(name,0);
        }

    }else{
        this->next();
        //define var with no path
        double value = toDouble->calculateExp(this->getString());
        symbolTable->setDoubleValue(name,value);

    }
    this->next();




}
