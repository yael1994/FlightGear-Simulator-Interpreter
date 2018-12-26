
#include "PrintCommand.h"
#include "SymbolTable.h"

/**
 * the function print the input.
 */
void PrintCommand::execute() {
    SymbolTable* p=SymbolTable::getInstance();
    this->next();
    while (this->getString()!="\n"){
        if(p->getSymbolTable().count(this->getString())>0){
            cout<< p->getValue(this->getString());
            this->next();

        } else {
            cout<< this->getString();
            this->next();
        }

    }
    cout<<endl;
    this->next();
}
/**
 * constructor of the print class.
 * @param iterator the iterator in the vector string input.
 */
PrintCommand::PrintCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}
