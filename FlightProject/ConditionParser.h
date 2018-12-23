//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_CONDITIONPARSER_H
#define UNTITLED4_CONDITIONPARSER_H


#include <vector>
#include "Command.h"
#include "IterCommand.h"
#include "SymbolTable.h"

#define OPERATOR {"<",">","<=",">=","==","!=","{","\n"}

class ConditionParser : public IterCommand{
    SymbolTable* symbolTable;
    map<string, Expression*> &mapCommand;
    string convertToString();

public:
    ConditionParser(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    ConditionParser(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
            const map<string, Expression *> &mapCommand);

    ConditionParser(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
            map<string, Expression *> &mapCommand);

    bool getCondition();
    void createCommandMap();
    void setMapCommand(map<string,Expression*> &map1);

protected:
    //ConditionParser(vector<string> *&pointer);
    vector<Expression*> m_commandVec;

};


#endif //UNTITLED4_CONDITIONPARSER_H