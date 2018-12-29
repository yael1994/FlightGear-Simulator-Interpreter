
#ifndef UNTITLED4_EXPRESSIONSINGLETONE_H
#define UNTITLED4_EXPRESSIONSINGLETONE_H
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "CreateExp.h"
using namespace std;
/**
 * This class convert strings to Expression.
 * bind the Expression to the commands
 */
class ExpressionSingleTone {
    static ExpressionSingleTone* _instance;

   CreateExp* createExp;

public:
    ExpressionSingleTone()  {
        createExp = new CreateExp();
    }

public:
    static ExpressionSingleTone* getInstance(){
        if(_instance == NULL){
            _instance = new ExpressionSingleTone();
        }
        return _instance;
    }

    double calculateExp(string exp){
        return createExp->buildExp(exp)->calculate();
    }

    ~ExpressionSingleTone(){
        delete createExp;
    }






};


#endif //UNTITLED4_EXPRESSIONSINGLETONE_H
