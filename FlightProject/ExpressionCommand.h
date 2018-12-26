//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_EXPRESSIONCOMAND_H
#define UNTITLED4_EXPRESSIONCOMAND_H


#include "Command.h"
#include "Expression.h"
/**
 * this class is part of :Object Adapter" design pattern that connect between "Command" and "Expression"
 * this class inheritage the Expression
 */
class ExpressionCommand : public Expression{
    Command* c;
public:

    ExpressionCommand(Command *c);

    double calculate() override;


};


#endif //UNTITLED4_EXPRESSIONCOMAND_H
