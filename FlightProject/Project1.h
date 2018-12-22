//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED4_PROJECT1_H
#define UNTITLED4_PROJECT1_H

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "Command.h"
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "setCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"

class Project1 {
    map<string,Expression*> commandMap;
    vector<string> rawData;
    vector<string>::iterator iter;
        void bulidMap(){
            commandMap["openDataServer"]= new ExpressionCommand(new OpenDataServerCommand(iter));
            commandMap["connect"]= new ExpressionCommand(new ConnectCommand(iter));
            commandMap["var"] = new ExpressionCommand(new DefineVarCommand(iter));
            commandMap["set"] = new ExpressionCommand(new setCommand(iter));
            commandMap["if"] = new ExpressionCommand(new IfCommand(iter));
            commandMap["while"] = new ExpressionCommand(new LoopCommand(iter));
        }

public:
        const map<string, Expression *> &getCommandMap() {
            return commandMap;
        }


    Project1( string filename);
        Project1 ()= default;
    void run();




};


#endif //UNTITLED4_PROJECT1_H
