//
// Created by solod on 06.07.2022.
//

#include <vector>
#include "FileReader.h"
class TransportsReader : public FileReader{
public:
    TransportsReader(const std::string&path);
    std::vector<std::string> readInfoTransports();
};
