
#include <unistd.h>
#include "SleepCommand.h"

SleepCommand::SleepCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}
/**
 * Sleep the running
 */
void SleepCommand::execute() {
this->next();
    int second = toDouble->calculateExp(this->getString());
    sleep(second/1000);
    this->next();
    while(this->getString() == "\n") {
        this->next();
    }
}
