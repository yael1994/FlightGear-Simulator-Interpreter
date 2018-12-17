//
// Created by yael on 12/14/18.
//

#include "Mul.h"
/**
 * the function multiply between the left expression to the right expression.
 * @return the expression after the multiply.
 */
double Mul::calculate() {
    if(this->getRight()->calculate()==0||this->getLeft()->calculate()==0){
        return 0;
    }

    return this->getLeft()->calculate()*this->getRight()->calculate();
}
