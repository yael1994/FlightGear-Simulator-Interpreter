//
// Created by daniel on 12/14/18.
//

#include "IfCommand.h"
#include "IterCommand.h"


void IfCommand::execute(){
    if (getCondition()){
        while (this->getString()!="{"){
            this->next();
        }
        this->next();
        createCommandMap();
        for (int i=0;i<m_commandVec.size();i++){
            m_commandVec.at(i)->calculate();
        }
    } else{
        while (this->getString()!="}"){
            this->next();
        }
    }
//to jump over the "}"
    this->next();
    if(this->getString() == "\n"){
        this->next();
    }
}

//IfCommand::IfCommand(
//        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
//        const map<string, Expression *> &mapCommand) : ConditionParser(iterator, mapCommand) {}
IfCommand::IfCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        map<string, Expression *> &mapCommand) : ConditionParser(iterator, mapCommand) {}
