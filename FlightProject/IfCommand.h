
#ifndef UNTITLED4_IFCOMMAND_H
#define UNTITLED4_IFCOMMAND_H

#include "ConditionParser.h"
#include "IterCommand.h"



class IfCommand : public ConditionParser{

public:
    IfCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
            unordered_map<string, Expression *> &mapCommand);


/**
 * implements the command interface
 */

    void execute() override;

};


#endif //UNTITLED4_IFCOMMAND_H