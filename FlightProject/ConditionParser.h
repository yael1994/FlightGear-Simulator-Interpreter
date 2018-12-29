
#ifndef UNTITLED4_CONDITIONPARSER_H
#define UNTITLED4_CONDITIONPARSER_H


#include <vector>
#include "Command.h"
#include "IterCommand.h"
#include "SymbolTable.h"

#define OPERATOR {"<",">","<=",">=","==","!","{","\n","="}

class ConditionParser : public IterCommand{
    SymbolTable* symbolTable;
    string convertToString();

    bool isOperator(const string &str);

protected:
    unordered_map<string, Expression*> &mapCommand;
public:
    ConditionParser(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
            unordered_map<string, Expression *> &mapCommand);

    bool getCondition();
    void runCommand();
    int countLoop();
};


#endif //UNTITLED4_CONDITIONPARSER_H