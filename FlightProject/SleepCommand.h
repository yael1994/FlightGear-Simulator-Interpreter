//
// Created by daniel on 12/22/18.
//

#ifndef FLIGHTPROJECT_SLEEPCOMMAND_H
#define FLIGHTPROJECT_SLEEPCOMMAND_H


#include "IterCommand.h"

class SleepCommand : public IterCommand{
public:
    SleepCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    void execute() override;

};


#endif //FLIGHTPROJECT_SLEEPCOMMAND_H
