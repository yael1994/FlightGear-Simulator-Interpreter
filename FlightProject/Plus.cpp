//
// Created by yael on 12/14/18.
//

#include "Plus.h"


/**
 * the function plus between two expression.
 * @return the expression after the plus
 */
double Plus::calculate() {
    return (this->getLeft()->calculate()+this->getRight()->calculate());
}
