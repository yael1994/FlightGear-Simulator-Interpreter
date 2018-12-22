//
// Created by yael on 12/16/18.
//

#include <stack>
#include <stdexcept>
#include "CreateExp.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"
#include "Number.h"
#include "Neg.h"
#include "ShAlgo.h"

bool CreateExp::isOperator(const string &str) const {
    return (str == "+") || (str == "-") || (str == "*") || (str == "/");
}

bool CreateExp::isNumber(const string &str) const {
    if(str.empty()){
        return false;
    }
    for (unsigned long  i = 0; i < str.length(); i++) {
        if (str.at(i)<'0'||str.at(i)>'9'){
            if(str.at(i)!='.'){
                return false;
            }
        }
    }
    return true;
}

Expression* CreateExp::biuldExp(string str) {
    ShAlgo* sy=new ShAlgo();
    queue<string> q_num=sy->creatQueue(str);
    stack<Expression*> st;
    while (!q_num.empty()){
        string element = q_num.front();
        q_num.pop();

        if (isNumber(element)){
            Expression* exp=new Number(stod(element));
            st.push(exp);
        }
        if(isOperator(element)){
           if(element=="+"){
               if(st.size()<2){
                   throw runtime_error("there is no two expressions");
               }
               Expression *e1 = st.top();
               st.pop();
               Expression *e2 = st.top();
               st.pop();

               Expression *exp = new Plus(e2, e1);
               st.push(exp);
           }
            if(element=="-"){
                if(st.size()==1){
                    Expression* e3=st.top();
                    st.top();
                    Expression* exp=new Neg(e3);
                    st.push(exp);
                } else {
                    if(st.size()<2){
                        throw runtime_error ("there is no two expressions");
                    }
                    Expression *e1 = st.top();
                    st.pop();
                    Expression *e2 = st.top();
                    st.pop();
                    Expression *exp = new Minus(e2, e1);
                    st.push(exp);
                }
            }
            if(element=="*"){
                if(st.size()<2){
                    throw runtime_error ("there is no two expressions");
                }
                Expression* e1=st.top();
                st.pop();
                Expression* e2=st.top();
                st.pop();
                Expression* exp=new Mul(e2,e1);
                st.push(exp);
            }
            if(element=="/"){
                if(st.size()<2){
                    throw runtime_error ("there is no two expressions");
                }
                Expression* e1=st.top();
                st.pop();
                Expression* e2=st.top();
                st.pop();
                Expression* exp=new Div(e2,e1);
                st.push(exp);
            }

        }

    }
    return st.top();
}
