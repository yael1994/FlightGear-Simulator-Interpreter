//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_CONNECTCOMMAND_H
#define UNTITLED4_CONNECTCOMMAND_H


#include "Command.h"
#include "IterCommand.h"

class ConnectCommand: public IterCommand {

public:


    ConnectCommand(
            const vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    ConnectCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    virtual void execute() override;


};


#endif //UNTITLED4_CONNECTCOMMAND_H
