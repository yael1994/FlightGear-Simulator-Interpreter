//
// Created by yael on 12/22/18.
//

#include "Utils.h"
#include <string>

bool Utils::isOperator(const string &str) {
    return (str == "+") || (str == "-") || (str == "*") || (str == "/");
}

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
