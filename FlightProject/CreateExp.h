#ifndef FLIGHTPROJECT_CREATEEXP_H
#define FLIGHTPROJECT_CREATEEXP_H
#include <unordered_map>
#include <string>
#include <queue>
#include "Expression.h"
using namespace std;

class CreateExp {

vector<Expression*> toDelete;
public:
    CreateExp()= default;
    Expression* buildExp(string str);

    virtual ~CreateExp();
};


#endif //FLIGHTPROJECT_CREATEEXP_H
