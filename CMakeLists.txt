cmake_minimum_required(VERSION 3.12)
project(FlightProject)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

include_directories(FlightProject)

add_executable(FlightProject
        FlightProject/BinaryExpression.cpp
        FlightProject/BinaryExpression.h
        FlightProject/ClientConnect.cpp
        FlightProject/ClientConnect.h
        FlightProject/Command.h
        FlightProject/ConditionParser.cpp
        FlightProject/ConditionParser.h
        FlightProject/ConnectCommand.cpp
        FlightProject/ConnectCommand.h
        FlightProject/CreateExp.cpp
        FlightProject/CreateExp.h
        FlightProject/DataReaderServer.cpp
        FlightProject/DataReaderServer.h
        FlightProject/DefineVarCommand.cpp
        FlightProject/DefineVarCommand.h
        FlightProject/Div.cpp
        FlightProject/Div.h
        FlightProject/Expression.cpp
        FlightProject/Expression.h
        FlightProject/ExpressionCommand.cpp
        FlightProject/ExpressionCommand.h
        FlightProject/ExpressionSingleTone.h
        FlightProject/IfCommand.cpp
        FlightProject/IfCommand.h
        FlightProject/IterCommand.h
        FlightProject/Lexer.cpp
        FlightProject/Lexer.h
        FlightProject/LoopCommand.cpp
        FlightProject/LoopCommand.h
        FlightProject/main.cpp
        FlightProject/Minus.cpp
        FlightProject/Minus.h
        FlightProject/Mul.cpp
        FlightProject/Mul.h
        FlightProject/NameToPathTable.h
        FlightProject/Neg.cpp
        FlightProject/Neg.h
        FlightProject/Number.cpp
        FlightProject/Number.h
        FlightProject/OpenDataServerCommand.cpp
        FlightProject/OpenDataServerCommand.h
        FlightProject/Parser.cpp
        FlightProject/Parser.h
        FlightProject/Plus.cpp
        FlightProject/Plus.h
        FlightProject/PrintCommand.cpp
        FlightProject/PrintCommand.h
        FlightProject/Project1.cpp
        FlightProject/Project1.h
        FlightProject/setCommand.cpp
        FlightProject/setCommand.h
        FlightProject/ShAlgo.cpp
        FlightProject/ShAlgo.h
        FlightProject/SymbolTable.cpp
        FlightProject/SymbolTable.h)
