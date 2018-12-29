#include <iostream>
#include "Project1.h"


SymbolTable* SymbolTable::_instance= NULL;



int main(int argc,char* argv[]) {
   if (argc!=2){
      throw runtime_error("there is problem with the argumants");
   }

   Project1* project1 = new Project1(argv[1]);
   project1->run();
   delete project1;
   return 0;
}