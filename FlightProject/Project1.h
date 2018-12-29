

#ifndef UNTITLED4_PROJECT1_H
#define UNTITLED4_PROJECT1_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Command.h"
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "setCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
/**
 * this class controls the spacific information of this project such as vector from lexer and
 * command map. with this seperation we can reuse our classes for other projects with no changes.
 */
class Project1 {
    unordered_map<string,Expression*> commandMap;
    vector<string> rawData;
    vector<string>::iterator iter;
    //built the commands map as we know from the script
    //each command warrped with `Exprrision Command for Object adapter
        void bulidMap(){
            commandMap["openDataServer"]= new ExpressionCommand(new OpenDataServerCommand(iter));
            commandMap["connect"]= new ExpressionCommand(new ConnectCommand(iter));
            commandMap["var"] = new ExpressionCommand(new DefineVarCommand(iter));
            commandMap["set"] = new ExpressionCommand(new setCommand(iter));
            commandMap["print"] = new ExpressionCommand(new PrintCommand(iter));
            commandMap["sleep"] = new ExpressionCommand(new SleepCommand(iter));
            commandMap["if"] = new ExpressionCommand(new IfCommand(iter,this->commandMap));
            commandMap["while"] = new ExpressionCommand(new LoopCommand(iter,this->commandMap));

        }


public:

        const unordered_map<string, Expression *> &getCommandMap() {
            return commandMap;
        }


    Project1( string filename);
        Project1 ()= default;
        /**
         * runs the project by opening a parser
         */
    void run();
    ~Project1(){
        for(auto i : commandMap){
            delete i.second;
        }

    }




};


#endif //UNTITLED4_PROJECT1_H
