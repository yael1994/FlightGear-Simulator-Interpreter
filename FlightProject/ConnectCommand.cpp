
#include <thread>
#include "ConnectCommand.h"
#include "SendMesagge.h"
#include "CreateExp.h"
#include "ExpressionSingleTone.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>


#include <string.h>

ExpressionSingleTone* ExpressionSingleTone::_instance = NULL;
/**
 * Constructor by IDE 
 * @param iterator 
 */
ConnectCommand::ConnectCommand(
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator)
        : IterCommand(iterator) {}

        
        
void ConnectCommand::execute() {
    this->next();
    string ip = this->getString();
    this->next();
    if(this->getString()==","){
        this->next();
    }
    int port =(int) toDouble->calculateExp(convertToString());
    this->next();
    SendMesagge::openClient(ip,port);

}





string ConnectCommand::convertToString() {
    string ans;
    while (this->getString()!="\n") {
        if(this->getString()==","){
            this->next();
            continue;
        }
        ans += this->getString();
        this->next();
    }
    return ans;
}
/**
 * 
 * this method open the socket for the client and whit to connection 
 * if there is a condition its open a thread for the message sendig 
 *
 * @param ip 
 * @param port 
 */
