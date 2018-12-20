//
// Created by daniel on 12/14/18.
//

#include "DefineVarCommand.h"


DefineVarCommand::DefineVarCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

void DefineVarCommand::execute() {
    this->next();
    string var = this->getString();
    this->next();




}
