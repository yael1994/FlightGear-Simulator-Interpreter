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
    this->next();
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
    vector<string> ::iterator it=this->getIter();
    while (*it!="}") {
        Expression *c = mapCommand.find(*it)->second;
        if (c != NULL) {
            m_commandVec.push_back(c);
        }
        it++;
    }
}

ConditionParser::ConditionParser(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {
    symbolTable= SymbolTable::getInstance();

}

void ConditionParser::setMapCommand(map<string, Expression *> &map1) {
    this->mapCommand = map1;
}

string ConditionParser::convertToString() {
    vector<string> operators=OPERATOR;
    string ans;
    this->next();
    while (find(operators.begin(), operators.end(), this->getString())!= operators.end()) {
        if (!Utils::isNumber(this->getString()) && !Utils::isOperator(this->getString())
            && (this->getString() != "(" || this->getString() != ")")) {
            ans += symbolTable->getValue(this->getString());
            this->next();
            continue;
        }
    }
    return ans;
}
