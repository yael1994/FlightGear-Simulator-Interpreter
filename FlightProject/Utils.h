//
// Created by yael on 12/22/18.
//

#ifndef FLIGHTPROJECT_UTILS_H
#define FLIGHTPROJECT_UTILS_H
#include <string>

using namespace std;

class Utils {
public:
    /**
 * the function check if the string is a simple operator.
 * @param str the string that the function check
 * @return true if it is a simple operator , else false.
 */
static bool isOperator(const string &str);
/**
 * the function check if the string is a simple number
 * @param str the string that the function check
 * @return true if it is a simple number, else false.
 */
static bool isNumber(const string &str);
};


#endif //FLIGHTPROJECT_UTILS_H
