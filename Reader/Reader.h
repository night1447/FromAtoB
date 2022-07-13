//
// Created by solod on 05.07.2022.
//
#include "string"

class Reader {
protected:
    void deleteUnwantedSymbol(std::string &basicString);

    std::string getStringLowerCase(const std::string &focus);

    int convertToNumber(const std::string &s);

public:
    Reader();
};


