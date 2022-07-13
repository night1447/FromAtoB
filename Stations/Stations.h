//
// Created by solod on 06.07.2022.
//
#include "../Transport/Transport.h"
#include "map"

class Stations {
    vector<string> stations;
    int size;

    vector<string> createVectorStations(const map<string, vector<Transport> > &mapStations);

public:
    Stations() : size(0) {}

    Stations(const map<string, vector<Transport> > &mapStations);

    Stations operator=(const Stations &focus);

    int getSize() const { return size; }

    vector<string> getStations() const { return stations; }

    int getIndexStationInStations(const string &station) const;

    ~Stations();
};


