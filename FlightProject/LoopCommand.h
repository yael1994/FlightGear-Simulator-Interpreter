//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_LOOPCOMMAND_H
#define UNTITLED4_LOOPCOMMAND_H


#include "ConditionParser.h"

class LoopCommand : public ConditionParser{
public:
    LoopCommand(vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    void execute() override;

};


#endif //UNTITLED4_LOOPCOMMAND_H