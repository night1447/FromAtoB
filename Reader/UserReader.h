//
// Created by solod on 06.07.2022.
//
#include "map"
#include "../Writer/Writer.h"
#include "ConsoleReader.h"
class UserReader : public ConsoleReader{
public:
    string readStation(const bool &isUserStation, const std::map<string, vector<Transport> > & mapStations);

    bool readUserChooseRoute();
};


