//
// Created by daniel on 12/14/18.
//

#include "OpenDataServerCommand.h"
#include "DataReaderServer.h"


//OpenDataServerCommand::OpenDataServerCommand(
//        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iter,
//        MapsSingleTone *controller) : iter(iter), controller(controller) {}

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
         int port = stoi(this->getString());
         this->next();
         int Hz = stoi(this->getString());
         this->next();
         
   //call DataReaderServer with object function
   thread thread1(DataReaderServer(), port,Hz);
   thread1.detach();

}



