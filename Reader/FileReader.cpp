//
// Created by solod on 06.07.2022.
//

#include "FileReader.h"
FileReader::FileReader(const std::string &path) : path(path){
    input.open(path);
    if (!input.is_open()) {
        throw Exception("К сожалению программа не может найти файл с информацией о транспорте");
    }
}

FileReader::~FileReader() {
    input.close();
}
