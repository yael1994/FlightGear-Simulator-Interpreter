//
// Created by yael on 12/14/18.
//

#ifndef FLIGHTPROJECT_SHALGO_H
#define FLIGHTPROJECT_SHALGO_H
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include "map"
using namespace std;


class ShAlgo {
    unordered_map<string,int > m_mapOperator;

    bool isOperator(const string &str) const;
    bool isNumber(const string &str) const;
    vector<string> splitString(string &str) const;
    int getPrecedence(const string &oper,const string &firstStac)const;
public:
    ShAlgo();
    ~ShAlgo();
    queue<string> creatQueue(string &expressions);
};


#endif //FLIGHTPROJECT_SHALGO_H
