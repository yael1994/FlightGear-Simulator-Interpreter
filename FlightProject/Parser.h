//
// Created by daniel on 12/13/18.
//

#ifndef UNTITLED4_PARSER_H
#define UNTITLED4_PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Command.h"
#include "ExpressionCommand.h"
#include "Project1.h"


using namespace std;
class Parser {

   vector<string>::iterator &iter;
   map<string, Expression*> _commandMap;
   vector<string>::iterator endIter;



public:

    Parser(vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iter,
           const map<string, Expression *> &_commandMap,
           const vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &endIter);

    void parse();

};


#endif //UNTITLED4_PARSER_H
