//
// Created by yael on 12/14/18.
//

#include <sstream>
#include "ShAlgo.h"
#include <stack>
#include <iostream>

/**
 * constructor of the class
 */
ShAlgo::ShAlgo() {
    //create map precedence of operators.
    m_mapOperator["+"] = 1;
    m_mapOperator["-"] = 1;
    m_mapOperator["*"] = 2;
    m_mapOperator["/"] = 2;
    m_mapOperator["("] = -1;
    //this->m_mapVar=varMap;
}
/**
 * distructor
 */
ShAlgo::~ShAlgo() {

}

/**
 * the function check if the string is a simple operator.
 * @param str the string that the function check
 * @return true if it is a simple operator , else false.
 */
bool ShAlgo::isOperator(const string &str) const {
    return (str == "+") || (str == "-") || (str == "*") || (str == "/");
}

/**
 * the function check if the string is a simple number
 * @param str the string that the function check
 * @return true if it is a simple number, else false.
 */
bool ShAlgo::isNumber(const string &str) const {
    if(str.empty()){
        return false;
    }
    for (unsigned long  i = 0; i < str.length(); i++) {
        if (str.at(i)<'0'||str.at(i)>'9'){
            if(str.at(i)!='.'){
            return false;
            }
        }
    }
    return true;
}

/**
 * the function check how add more precedence, between current operator to the top operator in the stack
 * @param oper the current operator
 * @param topStac the operator in the top of the stack
 * @return int number, if the number is 0 it mean that had the same precedence, if the numbrt is bigger then 1 so the
 * current operator have precedence.
 */
int ShAlgo::getPrecedence(const string &oper, const string &topStac) const {
    return m_mapOperator.at(oper)-m_mapOperator.at(topStac);

}
/**
 * the fucntion split the string and return a vector of strings
 * @param str the string to splite.
 * @return the string after splite at vector of strings.
 */
vector<string> ShAlgo::splitString(string &str) const {
    vector<string> splits;

    for (int i = 0; i < str.length(); i++) {
        string currChar = str.substr(i, 1);

        // check if the current char in the string  is a number
        string num;
       // string var;
        while (this->isNumber(currChar)) {
            num += currChar;
            i++;
            currChar = str.substr(i, 1);
        }
//        while (!this->isNumber(currChar)&&!this->isOperator(currChar)&&currChar!="(" &&currChar!=")"&&!currChar.empty()){
//            var+=currChar;
//            i++;
//            currChar=str.substr(i,1);
//        }
        // If this is a number put in the stack.
        if (!num.empty()) {
            splits.push_back(num);
            // Fixing position of 'i' due to the 'while' loop terminating
            i--;
//        } else if(!var.empty()){
//            double numOfVar=m_mapVar.at(var);
//            splits.push_back(to_string(numOfVar));
//            // Fixing position of 'i' due to the 'while' loop terminating
//            i--;
        }
        else {
            splits.push_back(currChar);
        }
    }
    return splits;
}

/**
 * the function create the queue at postfix order
 * @param expressions the strings to order
 * @return a queue in the postfix order.
 */
queue<string> ShAlgo::creatQueue(string &expressions) {
    vector<string> vec = this->splitString(expressions);
    stack<string> operators;
    queue<string> numbers;

    for (auto &str : vec) {
        if (this->isNumber(str)) {
            numbers.push(str);
        } else if (this->isOperator(str)) {
            // Moving bigger-precedence-operators from the stack to the queue
            while (!operators.empty() && this->getPrecedence(str, operators.top()) <= 0) {
                numbers.push(operators.top());
                operators.pop();
            }
            // add  current operator to the stack
            operators.push(str);
        } else if (str == "(") {
            operators.push(str);
        } else {        // 'str' is ')'
            // Moving all the operators to the queue until the top is '(' and remove it
            while (!operators.empty()) {
                string temp = operators.top();
                if (temp == "(") {
                    operators.pop();
                    break;
                }
                numbers.push(temp);
                operators.pop();
            }
        }
    }
    // Moving any remaining operators from the stack to the queue
    while (!operators.empty()) {
        numbers.push(operators.top());
        operators.pop();
    }
    return numbers;
}
//
//bool ShAlgo::isVar(const string &str) const {
//    return m_mapVar.count(str) == 1;
//}

