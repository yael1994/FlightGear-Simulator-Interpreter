
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


  ExpressionCommand(Command *c) : c(c) {
    }

    double calculate() {
        c->execute();
        return 0;
    }

    virtual ~ExpressionCommand() {
      delete this->c;
    }


};


#endif //UNTITLED4_EXPRESSIONCOMAND_H
