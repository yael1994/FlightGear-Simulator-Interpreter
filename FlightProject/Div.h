
#ifndef FLIGHTPROJECT_DIV_H
#define FLIGHTPROJECT_DIV_H


#include "BinaryExpression.h"

class Div: public BinaryExpression {
public:
    Div(Expression* left,Expression* right):BinaryExpression(left,right){};
    virtual double calculate();

    virtual ~Div();
};


#endif //FLIGHTPROJECT_DIV_H
