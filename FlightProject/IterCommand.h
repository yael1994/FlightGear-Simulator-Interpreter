//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED4_ITERCOMMAND_H
#define UNTITLED4_ITERCOMMAND_H


#include "Command.h"
#include "ExpressionSingleTone.h"

class IterCommand : public Command {

    vector<string>::iterator &iterator;

protected:
    ExpressionSingleTone* toDouble;
    string getString() {
        return *iterator;
    }
    vector<string>::iterator getIter(){
        return iterator;
    }
    void setIter(vector<string>::iterator iterator1){
        this->iterator = iterator1;
    }
    void next() {
        iterator++;
    }

public:
    virtual void execute()= 0;
    IterCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
            : iterator(iterator) {
        toDouble=ExpressionSingleTone::getInstance();
    }
};

#endif //UNTITLED4_ITERCOMMAND_H

