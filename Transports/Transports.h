//
// Created by solod on 05.07.2022.
//
#include "../Stations/Stations.h"
#include "sstream"
#include "algorithm"

class Transports {
protected:
    vector<Transport> transports;
    map<string, vector<Transport> > mapStations;
    Stations stations;

    vector<string> createStations(const string &line, int &positionStation);

    vector<string> getDataFromString(const string &line, const char &separator);

    Transport createTransport(const string &line, int &positionStation, const vector<string> &stationsVector);

public:
    void createMapStations(const string &line);
    void initStations(){
        Stations focus(mapStations);
        stations = focus;
    }
    Transports() {}

    ~Transports();

    int getSize() const { return stations.getSize(); }

    int getIndexStationInStations(const string &station) const;

    vector<string> getStations() const { return stations.getStations(); }

    map<string, vector<Transport>> getMap() { return mapStations; }

};


