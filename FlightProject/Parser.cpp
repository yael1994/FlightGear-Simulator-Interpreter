//
// Created by daniel on 12/13/18.
//

#include "Parser.h"
#include "ConnectCommand.h"
#include "OpenDataServerCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "ExpressionCommand.h"
#include "Lexer.h"
#include "SymbolTable.h"

Parser::Parser(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iter,
        const map<string, Expression *> &_commandMap,
        const vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &endIter)
        : iter(iter), _commandMap(_commandMap), endIter(endIter) {}


void Parser::parse() {
    int i = 0;
    int j =0;
    bool setFlag = true;
    while(iter != endIter) {
        if(*iter == "\n"){
            iter++;
        }
        if(_commandMap.count(*iter) > 0){

        Expression* c = _commandMap.find(*iter)->second;
            if(*iter == "if" || *iter == "while"){
                if(setFlag){
                    ConditionParser* conditionParser = dynamic_cast<ConditionParser*>(c);
                    if(conditionParser){
                        conditionParser->setMapCommand(this->_commandMap);
                    }
                }
            }
            c->calculate();
        }else{
            SymbolTable* stable = SymbolTable::getInstance();
            if(stable->getSymbolTable().count(*iter) > 0){
                Expression* c = _commandMap.find("set")->second;
                c->calculate();
            }
        }
        cout << i++ << endl;
        j++;
        if(j==12) {
            while (true) {
                if (i % 100000000000 == 0)
                    cout << i << endl;
                i++;
            }
        }
    }

}
