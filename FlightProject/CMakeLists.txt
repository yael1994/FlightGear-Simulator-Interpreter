cmake_minimum_required(VERSION 3.12)
project(untitled4)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
add_executable(untitled4 main.cpp Command.h Parser.cpp Parser.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h OpenDataServerCommand.cpp OpenDataServerCommand.h PrintCommand.cpp PrintCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h Expression.cpp Expression.h ExpressionCommand.cpp ExpressionCommand.h DataReaderServer.cpp DataReaderServer.h ClientConnect.cpp ClientConnect.h setCommand.cpp setCommand.h Lexer.cpp Lexer.h IterCommand.h SymbolTable.cpp SymbolTable.h Project1.cpp Project1.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h Neg.cpp Neg.h ShAlgo.cpp ShAlgo.h CreateExp.cpp CreateExp.h NameToPathTable.h ExpressionSingleTone.h)