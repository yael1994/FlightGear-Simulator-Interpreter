//
// Created by yael on 12/16/18.
//

#ifndef FLIGHTPROJECT_CREATEEXP_H
#define FLIGHTPROJECT_CREATEEXP_H
#include <unordered_map>
#include <string>
#include <queue>
#include "Expression.h"
using namespace std;

class CreateExp {
    bool isOperator(const string &str) const;
    bool isNumber(const string &str) const;

public:
    CreateExp()= default;
    Expression* biuldExp(string str);
};


#endif //FLIGHTPROJECT_CREATEEXP_H
