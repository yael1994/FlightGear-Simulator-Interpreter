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

using namespace std;


class ShAlgo {
    unordered_map<string,double > m_mapOperator;
    unordered_map<string,int > m_mapVar;

    bool isOperator(const string &str) const;
    bool isNumber(const string &str) const;
    bool isVar(const string &str) const;
    vector<string> splitString(string &str) const;
    vector<string> biuldVecSplit(vector<string> &expressions) const;
    int getPrecedence(const string &oper,const string &firstStac)const;
public:
    explicit ShAlgo(unordered_map<string,int > &varMap);
    ~ShAlgo();
    queue<string> creatQueue(vector<string> &expressions);
};


#endif //FLIGHTPROJECT_SHALGO_H
