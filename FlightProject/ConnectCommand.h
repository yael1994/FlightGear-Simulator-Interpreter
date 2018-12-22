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
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);
    static void openClient(string &ip, int port);
    virtual void execute() override;


};


#endif //UNTITLED4_CONNECTCOMMAND_H
