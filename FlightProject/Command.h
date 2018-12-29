

#ifndef UNTITLED4_COMMAND_H
#define UNTITLED4_COMMAND_H

#include <string>
#include <vector>
#include<iostream>
#include <mutex>

using namespace std;
static mutex thisLock;
/**
 * Interface
 */
class Command{
public:
    virtual void execute() = 0;
};


#endif //UNTITLED4_COMMAND_H
