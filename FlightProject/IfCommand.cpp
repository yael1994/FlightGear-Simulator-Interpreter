
#include "IfCommand.h"
#include "IterCommand.h"

/**
 * the function make if loop
 */
void IfCommand::execute(){
    //check if the condition is true.
    int count=0;
    count=countLoop();

    if (getCondition()) {
        while (this->getString()!="{"){
            this->next();
        }
        this->next();
        if(this->getString() == "\n")
        {
            this->next();
        }
        runCommand();
    } else{
        while (this->getString()!="}"){
            this->next();
        }
    }
    while (count!=0){
        if(this->getString()=="}"){
            count--;
        }
    }
//to jump over the "}"
    this->next();
    if(this->getString() == "\n"){
        this->next();
    }
}
/**
 * the constructor of the if class.
 * @param iterator iterator on the vector string input.
 * @param mapCommand the command map.
 */
IfCommand::IfCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator,
        map<string, Expression *> &mapCommand) : ConditionParser(iterator, mapCommand) {}
