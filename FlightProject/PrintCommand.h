//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_PRINTCOMMAND_H
#define UNTITLED4_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command {
public:
    PrintCommand();

    PrintCommand(vector<string> *&pointer);

    void execute() override;


};


#endif //UNTITLED4_PRINTCOMMAND_H
