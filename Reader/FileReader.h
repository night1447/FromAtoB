//
// Created by solod on 06.07.2022.
//
#include "../Exception.h"
#include "Reader.h"
#include "fstream"
class FileReader : public Reader{
protected:
    std::ifstream input;
    std::string path;
public:
    FileReader(const std::string&path);
    ~FileReader();
};


