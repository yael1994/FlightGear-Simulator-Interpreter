
#ifndef UNTITLED4_PATHTONAMETABLE_H
#define UNTITLED4_PATHTONAMETABLE_H



#include <map>
#include <string>
#include <mutex>
#include <fstream>
#include <iostream>

#define XML "generic_small.xml"
using namespace std;

class NameToPathTable {
    static NameToPathTable* _instance;
    mutex myLock;

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
        myLock.lock();
        this->nameToPath[key] = value;
        myLock.unlock();
    }
    const string& getPath(string key){

            return this->nameToPath.find(key)->second;

    }
    bool countPath(string name){
        return this->nameToPath.count(name) > 0;
    }
    const int& getIndex(string key){
        return this->pathToIndex.find(key)->second;
    }
    unsigned long getPathSize(){
        return this->pathToIndex.size();
    }
    bool countPathToIndex(string path){
        return  this->pathToIndex.count(path)> 0;
    }
    unsigned long getNamesSize(){
        return this->nameToPath.size();
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
