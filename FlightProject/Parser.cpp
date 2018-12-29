

#include "Parser.h"
#include "ConnectCommand.h"
#include "OpenDataServerCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "ExpressionCommand.h"
#include "Lexer.h"
#include "SymbolTable.h"

#define ENDFILE "$"
Parser::Parser(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iter,
        const unordered_map<string, Expression *> &_commandMap, const vector<string> &vector1) : iter(iter),
                                                                                       _commandMap(_commandMap),
                                                                                       vector1(vector1) {}

void Parser::parse() {
    int i = 0;
    bool setFlag = true;
    while(*iter != ENDFILE) {
        if(*iter == "}" ){
            iter++;
            iter++;
        }

        if(_commandMap.count(*iter) > 0){

        Expression* c = _commandMap.find(*iter)->second;
        if(c!= NULL) {
            c->calculate();
        }
        }else{
            SymbolTable* stable = SymbolTable::getInstance();
            if(stable->getSymbolTable().count(*iter) > 0){
                Expression* c = _commandMap.find("set")->second;
                c->calculate();
            }
        }
       // cout << i++ << endl;
    }

}
