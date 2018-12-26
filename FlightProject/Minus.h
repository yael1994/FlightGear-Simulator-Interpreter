#ifndef FLIGHTPROJECT_MINUS_H
#define FLIGHTPROJECT_MINUS_H


#include "BinaryExpression.h"

class Minus: public BinaryExpression {
public:
    Minus(Expression* left,Expression* right):BinaryExpression(left,right){};
    virtual double calculate();
    ~Minus()= default;
};


#endif //FLIGHTPROJECT_MINUS_H
