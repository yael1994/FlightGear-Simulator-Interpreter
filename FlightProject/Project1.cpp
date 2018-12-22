//
// Created by daniel on 12/18/18.
//

#include "Project1.h"
#include "Lexer.h"
#include "Parser.h"


Project1::Project1(string fileName)  {
    Lexer* lexer = new Lexer();
    this->rawData = lexer->lexer(fileName);
    this->iter = this->rawData.begin();
    bulidMap();

}

void Project1::run() {

    Parser* p = new Parser(this->iter,this->getCommandMap(),rawData.end());
    p->parse();


}




