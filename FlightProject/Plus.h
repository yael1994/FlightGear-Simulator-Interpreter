//
// Created by yael on 12/14/18.
//

#ifndef FLIGHTPROJECT_PLUS_H
#define FLIGHTPROJECT_PLUS_H


#include "BinaryExpression.h"

class Plus: public BinaryExpression {
public:
    Plus(Expression* left,Expression* right):BinaryExpression(left,right){};
    virtual double calculate();

};


#endif //FLIGHTPROJECT_PLUS_H
