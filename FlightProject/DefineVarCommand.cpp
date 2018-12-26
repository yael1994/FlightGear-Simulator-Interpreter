#include "DefineVarCommand.h"
#include "NameToPathTable.h"
#include "SymbolTable.h"
#include "Utils.h"

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
            symbolTable->setDoubleValue(name,0,0);  }
        else {
            //bind to other var that already bind, find the path of him and put it
            table->setPathValue(name, table->getPath(this->getString()));
            symbolTable->setDoubleValue(name,0,0);
        }
        this->next();
    }else{
        string ans;
        while (this->getString()!="\n"){
            if(!Utils::isNumber(this->getString())&&!Utils::isOperator(this->getString())
               &&(this->getString()!="("||this->getString()!=")")){
                ans+=to_string(symbolTable->getValue(this->getString()));
                this->next();
                continue;
            }
            ans+=this->getString();
            this->next();
        }
        //define var with no path
        double value = toDouble->calculateExp(ans);
        symbolTable->setDoubleValue(name,value,0);

    }
    this->next();


}
