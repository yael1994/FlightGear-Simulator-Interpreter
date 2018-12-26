
#include "Minus.h"
/**
 * the function minus between two expression.
 * @return the function minus the left expression to the right expression.
 */
double Minus::calculate() {
    return this->getLeft()->calculate()-this->getRight()->calculate();
}
