//
// Created by daniel on 12/14/18.
//

#ifndef UNTITLED4_EXPRESSIONCOMAND_H
#define UNTITLED4_EXPRESSIONCOMAND_H


#include "Command.h"
#include "Expression.h"

class ExpressionCommand : public Expression{
    Command* c;
public:
    ExpressionCommand(const Command &c);

    ExpressionCommand(Command *c);

    double calculate() override;


};


#endif //UNTITLED4_EXPRESSIONCOMAND_H
