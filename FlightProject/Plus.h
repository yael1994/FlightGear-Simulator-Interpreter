
#ifndef FLIGHTPROJECT_PLUS_H
#define FLIGHTPROJECT_PLUS_H


#include "BinaryExpression.h"

class Plus: public BinaryExpression {
public:
    Plus(Expression* left,Expression* right):BinaryExpression(left,right){};
    virtual double calculate();
    ~Plus()= default;
};


#endif //FLIGHTPROJECT_PLUS_H
