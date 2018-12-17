//
// Created by yael on 12/14/18.
//

#include "Number.h"

/**
 * the function calculate the number.
 * @return the member number
 */
double Number::calculate() {
    return this->m_number;
}
/**
 * the constructor of function Number.
 * @param number the parameter for initialization the member
 */
Number:: Number(double number) {
    this->m_number=number;
}
