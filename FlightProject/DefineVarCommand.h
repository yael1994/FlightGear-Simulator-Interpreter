//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_DEFINEVARCOMMAND_H
#define UNTITLED4_DEFINEVARCOMMAND_H


#include "Command.h"
#include "IterCommand.h"
#include <map>
#include <vector>

class DefineVarCommand: public IterCommand {
public:


    DefineVarCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    virtual void execute() override;

};


#endif //UNTITLED4_DEFINEVARCOMMAND_H
