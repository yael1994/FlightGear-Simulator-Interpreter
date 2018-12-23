//
// Created by daniel on 12/14/18.
//

#include "ConditionParser.h"

//
// Created by daniel on 12/14/18.
//
#include "algorithm"
#include "ConditionParser.h"
#include "iterator"
#include "Project1.h"
#include "Utils.h"
#include "SymbolTable.h"

/**
 * the function check if the condition of the loop or "if" is true or false.
 * @return true if the condition is right, else return false.
 */
bool ConditionParser:: getCondition(){
    string a1=convertToString();
   // this->next();
    string oper=this->getString();
    string a2=convertToString();
    vector<string> operators=OPERATOR;
    //all the condition that can be.
    if(oper=="!="){
        return ((toDouble->calculateExp(a1)!=toDouble->calculateExp(a2)));
    }
    if(oper=="<"){
        return ((toDouble->calculateExp(a1)<toDouble->calculateExp(a2)));
    }
    if (oper==">"){
        return ((toDouble->calculateExp(a1)>toDouble->calculateExp(a2)));
    }
    if (oper=="<="){
        return ((toDouble->calculateExp(a1)<=toDouble->calculateExp(a2)));
    }
    if (oper==">="){
        return ((toDouble->calculateExp(a1)>=toDouble->calculateExp(a2)));
    }
    if (oper=="=="){
        return ((toDouble->calculateExp(a1)==toDouble->calculateExp(a2)));
    }
}

void ConditionParser::createCommandMap(){
    bool flag=false;
    vector<string> ::iterator it=this->getIter();
    while (this->getString()!="}") {
            if(this->getString()== "=" || this->getString() == "print"){
                flag = true;
            }
            if((symbolTable->getSymbolTable().count(this->getString()) > 0)&&!flag) {
                Expression* c = mapCommand.find("set")->second;
                m_commandVec.push_back(c);
            } else {
                if(mapCommand.count(this->getString()) > 0){
                Expression *c = mapCommand.find(this->getString())->second;
                    m_commandVec.push_back(c);
                }
            }
            if(this->getString() == "\n"){
                flag = false;
            }
        this->next();
    }
    this->setIter(it);

}

ConditionParser::ConditionParser(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        map<string, Expression *> &mapCommand) : IterCommand(iterator), mapCommand(mapCommand) {
    symbolTable= SymbolTable::getInstance();
}

void ConditionParser::setMapCommand(map<string, Expression *> &map1) {
    this->mapCommand = map1;
}

string ConditionParser::convertToString() {
    vector<string> operators=OPERATOR;
    string ans;
    this->next();
    while (!(find(operators.begin(), operators.end(), this->getString()) != operators.end())) {
        if (!Utils::isNumber(this->getString()) && !Utils::isOperator(this->getString())
            && (this->getString() != "(" || this->getString() != ")")) {
            ans += to_string(symbolTable->getValue(this->getString()));
            this->next();
            continue;
        }else{
            ans+=this->getString();
            this->next();
        }
    }
    return ans;
}