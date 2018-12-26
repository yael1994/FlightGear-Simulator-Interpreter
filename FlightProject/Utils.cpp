
#include "Utils.h"
#include <string>
/**
 * the function check if the string is operator
 * @param str the string to check
 * @return if is an operator return true, else return false.
 */
bool Utils::isOperator(const string &str) {
    return (str == "+") || (str == "-") || (str == "*") || (str == "/");
}
/**
 * the function check if the string is number.
 * @param str the string to check
 * @return if is a number return true else return false.
 */
bool Utils::isNumber(const string &str) {
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
