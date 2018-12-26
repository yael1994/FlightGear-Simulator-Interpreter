

#ifndef UNTITLED4_COMMAND_H
#define UNTITLED4_COMMAND_H

#include <string>
#include <vector>
#include<iostream>


using namespace std;
/**
 * Interface
 */
class Command{
public:
    virtual void execute() = 0;
};


#endif //UNTITLED4_COMMAND_H
