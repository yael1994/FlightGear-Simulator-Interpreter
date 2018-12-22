//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED4_PATHTONAMETABLE_H
#define UNTITLED4_PATHTONAMETABLE_H



#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define XML "generic_small.xml"
using namespace std;

class NameToPathTable {
    static NameToPathTable* _instance;

    map<string,string> nameToPath;
    map<string,int> pathToIndex;
    NameToPathTable(){
        readXML();
    }

public:
    static NameToPathTable* getInstance(){
        if(_instance == NULL){
            _instance = new NameToPathTable();
        }
        return _instance;
    }

    void setPathValue(string key, string value){
        this->nameToPath[key] = value;
    }
    const string& getPath(string key){

        return this->nameToPath.find(key)->second;

    }
    const int& getIndex(string key){
        return this->pathToIndex.find(key)->second;
    }

private:
    void readXML(){
        int i = 0;
        int nodeSize = sizeof("<node>");
        ifstream in;
        string line;
        in.open(XML);
        if (!in.is_open()) {
            cout << "error while opening the file\n";
            exit(0);
        }
        while (!in.eof()) {
            in >> line;

            if(!line.compare(0,nodeSize-1,"<node>")){

                line.erase(0,nodeSize-1);
                line.erase(line.end()-nodeSize,line.end());
                pathToIndex[line] = i;
                i++;
            }
        }
        in.close();
    }

};


#endif //UNTITLED4_PATHTONAMETABLE_H
