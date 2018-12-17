//
// Created by yael on 12/14/18.
//

#include "Neg.h"
/**
 * the constructor of class negative.
 * @param epx get expression.
 */
Neg::Neg(Expression* epx) {
    this->m_exp=epx;
}
/**
 * the function calculate the expression and add minus to all the expression.
 * @return
 */
double Neg::calculate() {
    return -(this->m_exp->calculate());
}
