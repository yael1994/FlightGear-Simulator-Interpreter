//
// Created by yael on 12/13/18.
//

#ifndef FLIGHTPROJECT_LEXER_H
#define FLIGHTPROJECT_LEXER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Lexer{
    vector<string> m_vec;
    string parseApostrophes(string word);
    vector<string> lexFile(ifstream &in);
    vector<string> lexStr(string &str);

public:
    vector<string> lexer(string fileName);
};


#endif //FLIGHTPROJECT_LEXER_H
