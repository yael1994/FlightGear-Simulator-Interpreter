

#include "LoopCommand.h"
#include "Parser.h"

/**
 * the function make the loop of a while.
 */
void LoopCommand::execute() {
    vector<string> ::iterator it=this->getIter();
    int count=0;
    count=countLoop();
    //while loop
    while (getCondition()) {
        while (this->getString()!="{"){
            this->next();
        }
        this->next();
        if(this->getString() == "\n")
        {
            this->next();
        }
        runCommand();
        this->setIter(it);
    }
    while (count!=0){
        if(this->getString()=="}"){
            count--;
        }
        this->next();
    }
    //over on "}"
    this->next();
    if(this->getString() == "\n"){
        this->next();
    }

}
/**
 * constractor of the class.
 * @param iterator the iterator on the vector string input.
 * @param mapCommand map all the command at the simulator.
 */
LoopCommand::LoopCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        map<string, Expression *> &mapCommand) : ConditionParser(iterator, mapCommand) {}
