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
#include "IfCommand.h"

class Project1 {
    static map<string,Expression*> commandMap;
    vector<string> rawData;
    vector<string>::iterator iter;
        void bulidMap(){
            commandMap["openDataServer"]= new ExpressionCommand(new OpenDataServerCommand(iter));
            commandMap["connect"]= new ExpressionCommand(new ConnectCommand(iter));
            commandMap["var"] = new ExpressionCommand(new DefineVarCommand(iter));
            commandMap["if"]=new ExpressionCommand(new IfCommand(iter));

        }

public:
        static const map<string, Expression *> &getCommandMap(){
            return commandMap;
        }


    Project1( string filename);
    void run();




};


#endif //UNTITLED4_PROJECT1_H
