

#ifndef UNTITLED4_PARSER_H
#define UNTITLED4_PARSER_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Command.h"
#include "ExpressionCommand.h"
#include "Project1.h"


using namespace std;
class Parser {

   vector<string>::iterator &iter;
    unordered_map<string, Expression*> _commandMap;
   vector<string> vector1;




public:
    Parser(vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iter,
           const unordered_map<string, Expression *> &_commandMap, const vector<string> &vector1);

    void parse();


};


#endif //UNTITLED4_PARSER_H
