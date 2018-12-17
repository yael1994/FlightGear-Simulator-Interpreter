//
// Created by yael on 12/13/18.
//

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"

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

vector<string> Lexer::lexFile(ifstream &in){
    vector<string> lexVec;
    string line;
    string line1;
    // the function add the last number.
    while (!in.eof()) {
        in >> line;
        if (line[0]=='\"'){
            line=parseApostrophes(line);
        }
        lexVec.push_back(line);
    }
}

vector<string> Lexer::lexStr(string &str){
    string delimiter = " ";
    string line;
    while(str.find(delimiter)&&!str.empty()) {
        line=str.substr(0, str.find(delimiter));
        if (line[0]=='\"'){
            line=parseApostrophes(line);
        }
        this->m_vec.push_back(line);
        str.erase(0, str.find(delimiter) + delimiter.length());
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
    if (fileName.find(TXT) != std::string::npos) {
        ifstream in;
        in.open(fileName);
        if (!in.is_open()) {
            cout << "error while opening the file\n";
            exit(0);
        }
        this->m_vec=lexFile(in);
        in.close();
    } else{
        this->m_vec=lexStr(fileName);

    }
    return this->m_vec;
}


