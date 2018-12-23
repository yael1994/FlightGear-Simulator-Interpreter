//
// Created by daniel on 12/14/18.
//

#include "LoopCommand.h"


void LoopCommand::execute() {
    //save the place of the iterator
    vector<string> ::iterator it=this->getIter();
    while (getCondition()) {
        while (this->getString()!="{"){
            this->next();
        }
        this->next();
        if(this->getString() == "\n")
        {
            this->next();
        }
       if(m_commandVec.empty()) {
           createCommandMap();
       }
        for (int i=0; i < m_commandVec.size(); i++) {
            m_commandVec.at(i)->calculate();
        }
        this->setIter(it);
    }
    while (this->getString()!="}"){
        this->next();
    }
    //to jump over the "}"
    this->next();
    if(this->getString()=="\n"){
        this->next();
    }
}


LoopCommand::LoopCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        const map<string, Expression *> &mapCommand) : ConditionParser(iterator, mapCommand) {
}
