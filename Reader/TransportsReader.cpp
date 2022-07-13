//
// Created by solod on 06.07.2022.
//

#include "TransportsReader.h"

TransportsReader::TransportsReader(const std::string&path) : FileReader(path){
}
std::vector<std::string> TransportsReader::readInfoTransports() {
    std::string line;
    std::vector<std::string> lines;
    while (getline(input, line)) {
        deleteUnwantedSymbol(line);
        lines.push_back(line);
    }
    return lines;
}