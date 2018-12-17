//
// Created by yael on 12/14/18.
//

#ifndef FLIGHTPROJECT_NUMBER_H
#define FLIGHTPROJECT_NUMBER_H

#include "Expression.h"

class Number: public Expression {
    double m_number;
public:
    Number(double number);
    virtual double calculate();

};


#endif //FLIGHTPROJECT_NUMBER_H
