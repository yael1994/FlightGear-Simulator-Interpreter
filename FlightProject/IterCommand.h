//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED4_ITERCOMMAND_H
#define UNTITLED4_ITERCOMMAND_H


#include "Command.h"
#include "ExpressionSingleTone.h"
/**
 * this class is an abstract class that implements the command interface and collect all the shared members
 */
class IterCommand : public Command {

    vector<string>::iterator &iterator;

protected:
    ExpressionSingleTone* toDouble;
    /**
     * get the current string that the iterator point at
     * @return
     */
    string getString() {
        return *iterator;
    }
    /**
     * get the current iterator
     * @return
     */
    vector<string>::iterator getIter(){
        return iterator;
    }
    /**
     * set the iteratot
     * @param iterator1
     */
    void setIter(vector<string>::iterator iterator1){
        this->iterator = iterator1;
    }
    /**
     * increnet the iterator value
     */
    void next() {
        iterator++;
    }

public:
    virtual void execute()= 0;
    /**
     * constructor from the IDE
     * @param iterator
     */
    IterCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
            : iterator(iterator) {
        toDouble=ExpressionSingleTone::getInstance();
    }
};

#endif //UNTITLED4_ITERCOMMAND_H

