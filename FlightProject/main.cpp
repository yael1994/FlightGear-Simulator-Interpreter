#include <iostream>
#include "Lexer.h"
#include "ShAlgo.h"
#include <deque>
#include <iostream>
#include "CreateExp.h"
int main() {
//    vector<string> ex;
//    ex.push_back("-");
//    ex.push_back("(5+4");
//    ex.push_back(")");
//
//    ShAlgo* sy=new ShAlgo();
//    queue<string> r=sy->creatQueue(ex);
//    CreateExp* cr=new CreateExp();
//    Expression* epr=cr->biuldExp(r);
//    double num=epr->calculate();
//    cout<<num<<endl;

    Lexer* lex=new Lexer;
    vector<string> ex=lex->lexer("com.txt");
    cout<<"finish"<<endl;

    return 0;
}