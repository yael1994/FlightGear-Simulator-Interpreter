#include <iostream>
#include "Lexer.h"
#include "ShAlgo.h"
#include <deque>
#include <iostream>
#include "CreateExp.h"
int main() {
//   vector<string> ex;
//    ex.push_back("-");
//    ex.push_back("(5+4");
//    ex.push_back(")");
//
//    ShAlgo* sy=new ShAlgo();
//    queue<string> r=sy->creatQueue(ex);
////    CreateExp* cr=new CreateExp();
////    Expression* epr=cr->biuldExp(r);
////    double num=epr->calculate();
////    cout<<num<<endl;

//
    string s="(5-7)";
//    unordered_map<string, double > m;
//    m["kom"]=5;
    CreateExp* c=new CreateExp();
    Expression* e=c->biuldExp(s);
    cout<<e->calculate()<<endl;

//
//     Lexer* le=new Lexer;
//    vector<string> ex=le->lexer("com.txt");

    return 0;
}