

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "SymbolTable.h"
#include "NameToPathTable.h"

#define XML "generic_small.xml"
using namespace std;

class SendMesagge {

public:
    static void sendMsg(string msg);
    static void openClient(string ip, int port);

};
