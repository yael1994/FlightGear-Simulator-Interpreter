//
// Created by daniel on 12/14/18.
//

#include "OpenDataServerCommand.h"
#include "DataReaderServer.h"
#include "Utils.h"
#include <chrono>

OpenDataServerCommand::OpenDataServerCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

/**
 * this method part of command pattern. when command is "open data server" this method contiue to read the args she need
 * and call static function that opens data server accurding to the port number.
 * the server open in thread to contiue reading while the server waiting for client
 */
void OpenDataServerCommand::execute() {

         this->next();
         int port = (int) toDouble->calculateExp(convertToString());
         int Hz = (int) toDouble->calculateExp(convertToString());
         this->next();
         
   //call DataReaderServer with object function
   thread thread1(DataReaderServer(), port,Hz);
//   this_thread::__sleep_for(chrono::seconds(1000),chrono::microseconds(1));
   thread1.detach();
//   DataReaderServer d;
//   d.openServer(port,Hz);
}

string OpenDataServerCommand::convertToString() {
    bool flag=false;
    string ans;
    while (this->getString()!="\n") {
        if (Utils::isNumber(this->getString()) && !flag) {
            ans += this->getString();
            flag = true;
            this->next();
            continue;
        } else if (Utils::isOperator(this->getString())) {
            ans += this->getString();
            flag = false;
            this->next();
            continue;
        } else if ((Utils::isNumber(this->getString()) && flag) || this->getString() == ",") {
            return ans;
        }else{
            ans += this->getString();
            this->next();
        }
    }
}



