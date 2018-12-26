#include <iostream>
#include "Parser.h"
#include "SymbolTable.h"
#include "Project1.h"
#include "Lexer.h"

SymbolTable* SymbolTable::_instance= NULL;



int main() {
   SymbolTable* p = SymbolTable::getInstance();
   SymbolTable* q = SymbolTable::getInstance();



   Project1* project1 = new Project1("file.txt");
   project1->run();



   return 0;
}