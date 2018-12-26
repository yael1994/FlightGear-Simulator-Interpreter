
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
         
//   //call DataReaderServer with object function
//   thread thread1(DataReaderServer(), port,Hz);
// thread1.detach();
    int sockfd;

    int clilen;

    struct sockaddr_in serv_addr, cli_addr;
    int  n;

/* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    cout<<"S"<<endl;

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");

    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if(newsockfd >= 0){
        cout<<"open thread for server"<<endl;
           thread thread1(DataReaderServer(), newsockfd,Hz);
           thread1.detach();
    }

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
            if(this->getString()==","){
                this->next();
            }
            return ans;
        }else{
            ans += this->getString();
            this->next();
        }
    }
}



