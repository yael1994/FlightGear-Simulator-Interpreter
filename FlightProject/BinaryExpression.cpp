//
// Created by yael on 12/14/18.
//

#include "BinaryExpression.h"
/**
 * the function return the left expression.
 * @return expression left.
 */
Expression* BinaryExpression::getLeft() {
    return this->left;
}
/**
 * the function return the right expression.
 * @return expression right.
 */
Expression* BinaryExpression::getRight() {
    return this->right;
}
/**
 * the constructor the class binary expression.
 * @param ExLeft the left member.
 * @param ExRight the right member.
 */
BinaryExpression::BinaryExpression(Expression* ExLeft, Expression* ExRight) {
    this->left=ExLeft;
    this->right=ExRight;

}
