
#ifndef UNTITLED4_CONNECTCOMMAND_H
#define UNTITLED4_CONNECTCOMMAND_H


#include "Command.h"
#include "IterCommand.h"

class ConnectCommand: public IterCommand {

    string convertToString();



public:
    ConnectCommand(
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::iterator &iterator);

    /**
     * this method opens a socket for the client and call a thread for the message to send
     * @param ip from the user
     * @param port from the user
     */
    void openClient(string &ip, int port);

/**
 * implements the command interface
 */
    virtual void execute() override;
    virtual ~ConnectCommand(){

    }



};


#endif //UNTITLED4_CONNECTCOMMAND_H
