#include "Div.h"
#include "Number.h"
/**
 * the function calculate divide between the left expression to the right expression.
 * @return the function return the expression after the divide.
 */
double Div::calculate()  {
    //x/0 -> not posible
    if (this->getRight()->calculate()==0){
        throw ("can't divide at 0");
    }
    //0/x=0
    if (this->getLeft()->calculate()==0){
        return 0;
    }
    return this->getLeft()->calculate()/this->getRight()->calculate();
}
