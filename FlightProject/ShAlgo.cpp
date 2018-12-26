
#include <sstream>
#include "ShAlgo.h"
#include "Utils.h"
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
    m_mapOperator["&"]=3;
}
/**
 * distructor
 */
ShAlgo::~ShAlgo() {

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
        while (Utils::isNumber(currChar)) {
            num += currChar;
            i++;
            currChar = str.substr(i, 1);
        }

        if (!num.empty()) {
            splits.push_back(num);
            // Fixing position of 'i' due to the 'while' loop terminating
            i--;

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
    string lastStr=".";

    for (auto &str : vec) {
        if (Utils::isNumber(str)) {
            numbers.push(str);
        } else if (Utils::isOperator(str)) {

            if(Utils::isOperator(lastStr)&& str=="-"){
                str="&";
            }

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
        if(str!="("&&str!=")") {
            lastStr = str;
        }
    }
    // Moving any remaining operators from the stack to the queue
    while (!operators.empty()) {
        numbers.push(operators.top());
        operators.pop();
    }
    return numbers;
}