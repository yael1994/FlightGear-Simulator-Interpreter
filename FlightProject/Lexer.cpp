//
// Created by yael on 12/13/18.
//

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include <regex>
#define TXT "txt"

using namespace std;
/**
 * the function out the apostrophes.
 * @param word the word has apostrophes.
 * @return the word without apostrophes.
 */
string Lexer::parseApostrophes(string word){
    int lenghChar=1;
    char delimiter ='\"';
    word.erase(0, word.find(delimiter) + lenghChar);
    word.erase(word.size()-lenghChar, word.find(delimiter) + lenghChar);
    return word;
}
void Lexer::getSpace(string &str) {
    string ans;
    string ch;
    vector<string> special_operators = SPECIAL_OPERATOR;
    bool is_quotation = false;
    string::iterator it;
    for (it = str.begin(); it != str.end(); ++it) {
        ch = *it;
        if (ch == "\"") {
            is_quotation = !is_quotation;
            ans += ch;
            continue;
        }
        if ((find(special_operators.begin(), special_operators.end(), ch) != special_operators.end()) &&
            !is_quotation) {
            string to_replace = " " + ch + " ";
            ans += to_replace;
        } else {
            ans += ch;
        }
    }
    str = ans;
}

void Lexer::lexStr(string &str){
   getSpace(str);
    string line;
    string delimiter=SPACE;
    while(!str.empty()) {
        line=str.substr(0, str.find(delimiter));
        if (line[0]=='\"'){
            line=parseApostrophes(line);
        }
        if(line.empty()){
            str.erase(0, str.find(delimiter) + delimiter.length());
            continue;
        }
        this->m_vec.push_back(line);
        if(str.find(delimiter)==string::npos){
            str="";
        } else {
            str.erase(0, str.find(delimiter) + delimiter.length());
        }
    }
}


/**
 * the function get file or string and lexer it in the space and push every string to vector.
 * at the end of the function got vector of strings.
 * @param fileName file or string
 * @return vector of string.
 */
vector<string> Lexer:: lexer(string fileName) {
    //the function check if he got file or string
    if (fileName.find(TXT) != string::npos) {
        ifstream in;
        string line;
        in.open(fileName);
        if (!in.is_open()) {
            cout << "error while opening the file\n";
            exit(0);
        }
        while (!in.eof()) {
            getline(in, line);
            lexStr(line);
            this->m_vec.push_back("\n");
        }
        in.close();
    } else{
        lexStr(fileName);
        this->m_vec.push_back("\n");

    }
    return this->m_vec;
}

