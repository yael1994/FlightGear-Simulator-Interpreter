cmake_minimum_required(VERSION 3.12)
project(FlightProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(FlightProject main.cpp Lexer.cpp Lexer.h Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h Neg.cpp Neg.h ShAlgo.cpp ShAlgo.h CreateExp.cpp CreateExp.h)