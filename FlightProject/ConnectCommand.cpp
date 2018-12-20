//
// Created by daniel on 12/14/18.
//

#include <thread>
#include "ConnectCommand.h"
#include "ClientConnect.h"

#include "ExpressionSingleTone.h"
ExpressionSingleTone* ExpressionSingleTone::_instance=NULL;

/**
 * this
 */
void ConnectCommand::execute() {
    this->next();
    string ip = this->getString();
    this->next();
    int port =(int) toDouble->calculateExp(this->getString());
    this->next();
    thread t1(ClientConnect(),ip,port);
    t1.detach();
}

ConnectCommand::ConnectCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}


