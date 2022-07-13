//
// Created by solod on 05.07.2022.
//

#include "Reader.h"
#include "string"
#include "sstream"
Reader::Reader() {}

void Reader::deleteUnwantedSymbol(std::string &basicString) {
    if (basicString[basicString.length() - 1] == '\r') basicString.erase(basicString.length() - 1, 1);
}



std::string Reader::getStringLowerCase(const std::string &focus) {
    std::string result;
    for (char element: focus) result += tolower(element);
    return result;
}


int Reader::convertToNumber(const std::string &s) {
    std::stringstream ss;
    ss << s;
    int k = 0;
    ss >> k;
    return k;
}
