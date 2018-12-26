
#ifndef FLIGHTPROJECT_NEG_H
#define FLIGHTPROJECT_NEG_H
#include "Expression.h"


class Neg :public Expression{
    Expression* m_exp;
public:
    Neg(Expression* epx);
    virtual double calculate();
    ~Neg()= default;
};


#endif //FLIGHTPROJECT_NEG_H
