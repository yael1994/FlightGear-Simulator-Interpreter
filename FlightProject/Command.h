//
// Created by daniel on 12/13/18.
//

#ifndef UNTITLED4_COMMAND_H
#define UNTITLED4_COMMAND_H

#include <string>
#include <vector>
#include<iostream>


using namespace std;

class Command{
public:
    virtual void execute() = 0;
};


#endif //UNTITLED4_COMMAND_H
