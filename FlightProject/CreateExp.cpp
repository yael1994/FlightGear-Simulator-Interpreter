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
#include "Utils.h"
/**
 * the function biuld expretion from the queue that got form the algoritem
 * @param str the string to build from him expretion.
 * @return the expretion.
 */
Expression* CreateExp::biuldExp(string str) {
    ShAlgo* sy=new ShAlgo();
    queue<string> q_num=sy->creatQueue(str);
    stack<Expression*> st;
    while (!q_num.empty()){
        string element = q_num.front();
        q_num.pop();

        if (Utils::isNumber(element)){
            Expression* exp=new Number(stod(element));
            st.push(exp);
        }
        if(Utils::isOperator(element)||element=="&"){
           //check witch operator we have at the queue
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
           if(element=="&"){
               Expression* e3=st.top();
               st.pop();
               Expression* exp=new Neg(e3);
               st.push(exp);
           }
            if(element=="-"){
                if(st.size()==1){
                    Expression* e3=st.top();
                    st.pop();
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
