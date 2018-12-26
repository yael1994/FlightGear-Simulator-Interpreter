#include "Mul.h"
/**
 * the function multiply between the left expression to the right expression.
 * @return the expression after the multiply.
 */
double Mul::calculate() {
    //x*0=0*x=0
    if(this->getRight()->calculate()==0||this->getLeft()->calculate()==0){
        return 0;
    }

    return this->getLeft()->calculate()*this->getRight()->calculate();
}
