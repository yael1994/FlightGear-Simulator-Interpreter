
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

/**
 * the function put space at all the place we need
 * @param str the input str]ing
 */
void Lexer::getSpace(string &str) {
    string ans;
    string ch;
    //we want space near a spacial operator.
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
/**
 * the function parser the string by spaces.
 * @param str the input string to parse.
 */
void Lexer::lexStr(string &str){
   getSpace(str);
   bool flag = false;
    string line;
    //what to parse on.
    string delimiter=SPACE;
    while(!str.empty()) {
        line=str.substr(0, str.find(delimiter));
        //the function save the " off the print.
        if(line == "print"){
            flag = true;
        }
        //if the input have \ it took it out.
        if (line[0]=='\"' && !flag){
            line=parseApostrophes(line);
        }
        if(line.empty()){
            str.erase(0, str.find(delimiter) + delimiter.length());
            continue;
        }
        //push to a vector
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
            if(line == "\n" || line.empty()){
                continue;
            }
            lexStr(line);
            this->m_vec.push_back("\n");
        }
        in.close();
    } else{
        if(fileName != "\n"){
        lexStr(fileName);
            }
        this->m_vec.push_back("\n");


    }
    this->m_vec.push_back("$");
    return this->m_vec;
}

