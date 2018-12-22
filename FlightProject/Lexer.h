//
// Created by yael on 12/13/18.
//

#ifndef FLIGHTPROJECT_LEXER_H
#define FLIGHTPROJECT_LEXER_H

#define SPACE " "

#define SPECIAL_OPERATOR {"+","-","*","/", "\"","<",">","<=",">=","=="}

#include <vector>
#include <string>
#include <fstream>
#include <iostream>



using namespace std;

class Lexer{
    vector<string> m_vec;
    string parseApostrophes(string word);
    void lexStr(string &str);
    void getSpace(string &str);

public:
    Lexer(){}
    vector<string> lexer(string fileName);
};


#endif //FLIGHTPROJECT_LEXER_H
