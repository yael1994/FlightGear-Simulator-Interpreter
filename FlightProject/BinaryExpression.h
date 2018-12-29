
#ifndef FLIGHTPROJECT_BINARYEXPRESSION_H
#define FLIGHTPROJECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression :public Expression{
    Expression* right;
    Expression* left;
    public:
        BinaryExpression(Expression* ExLeft,Expression* ExRight);
        virtual Expression* getLeft();
        virtual Expression* getRight();
        virtual double calculate()=0;
        virtual ~BinaryExpression(){
            delete this->left;
            delete  this->right;
        }

};


#endif //FLIGHTPROJECT_BINARYEXPRESSION_H
