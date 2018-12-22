//
// Created by daniel on 12/16/18.
//

#ifndef UNTITLED4_SETCOMMAND_H
#define UNTITLED4_SETCOMMAND_H


#include "IterCommand.h"

class setCommand: public IterCommand {
public:
    setCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    void execute() override;

};


#endif //UNTITLED4_SETCOMMAND_H
