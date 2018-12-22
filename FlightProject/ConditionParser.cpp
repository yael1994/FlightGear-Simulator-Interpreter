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

/**
 * the function check if the condition of the loop or "if" is true or false.
 * @return true if the condition is right, else return false.
 */
bool ConditionParser:: getCondition(){
    string a1;
    string a2;
    string oper;
    vector<string> operators=OPERATOR;
    //create string of the left side of the operator.
    do {
        this->next();
        a1 += this->getString();
    }while (find(operators.begin(), operators.end(), this->getString())!= operators.end());
    oper= this->getString();
    //create string of the right side of the operator.
    do {
        this->next();
        a2 += this->getString();
    }while (this->getString()!= "\n"|| this->getString()!="{");


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
        : IterCommand(iterator) {}

void ConditionParser::setMapCommand(map<string, Expression *> &map1) {
    this->mapCommand = map1;
}
