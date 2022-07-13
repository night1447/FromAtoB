//
// Created by solod on 06.07.2022.
//
#include "TransportsReader.h"
#include "vector"
#include "iostream"
class ConsoleReader : public Reader{
public:
    ConsoleReader(){}
    std::string readChooseRoute(const std::vector<std::string> &chooses);
    bool checkAnswerConsole(const std::string &check);
};
