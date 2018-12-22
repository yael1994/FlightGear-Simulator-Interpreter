//
// Created by daniel on 12/14/18.
//

#include "LoopCommand.h"


void LoopCommand::execute() {
    vector<string> ::iterator it=this->getIter();
    while (getCondition()) {
        for (int i = 0; i < m_commandVec.size(); i++) {
            m_commandVec.at(i)->calculate();
        }
    }
    this->setIter(it);
}

LoopCommand::LoopCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : ConditionParser(iterator) {}