

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "SymbolTable.h"
#include "NameToPathTable.h"

#define XML "generic_small.xml"
using namespace std;

class SendMesagge {
    mutex myLock;
public:
    static void sendMsg(int socket);

};
