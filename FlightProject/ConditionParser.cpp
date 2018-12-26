#include "ConditionParser.h"
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
    //the left side of the condition.
    string a1=convertToString();
    //the operator of the condition.
    string oper=this->getString();
    //the right side of the condition.
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

/**
 * the function calculate the command of the while or the if.
 * @param vecCommand come empty
 * @return the vector with command.
 */
void ConditionParser::runCommand(){
    bool flag=false;
    vector<string> ::iterator it=this->getIter();
    while (this->getString()!="}") {
        if (this->getString() == "=" || this->getString() == "print") {
            flag = true;
        }
        if ((symbolTable->getSymbolTable().count(this->getString()) > 0) && !flag) {
            Expression *c = mapCommand.find("set")->second;
            c->calculate();
        } else {
            if (mapCommand.count(this->getString()) > 0) {
                Expression *c = mapCommand.find(this->getString())->second;
                c->calculate();
            }
        }
        if (this->getString() == "\n") {
            flag = false;
        }
    }
}
/**
 * the constructor of the class.
 * @param iterator the iterator on the vector string input.
 * @param mapCommand the map command
 */
ConditionParser::ConditionParser(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        map<string, Expression *> &mapCommand) : IterCommand(iterator), mapCommand(mapCommand) {
    symbolTable= SymbolTable::getInstance();
}
/**
 * the function put all the part of the condition at a one string.
 * @return the string of one side of consition.
 */
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

int ConditionParser::countLoop() {
    vector<string> ::iterator it=this->getIter();
    int countI=0;
    int countO=0;
    while(this->getString()!="{"){
        this->next();
    }
    countI++;
    this->next();
    while(countI!=countO){
        if(this->getString()=="{"){
            countI++;
        }
        if(this->getString()=="}"){
            countO++;
        }
        this->next();
    }
    setIter(it);
    return countI;
}
