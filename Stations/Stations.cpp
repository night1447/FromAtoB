//
// Created by solod on 06.07.2022.
//

#include "Stations.h"
#include "algorithm"

Stations::Stations(const map<string, vector<Transport>> &mapStations) {
    this->stations = createVectorStations(mapStations);
    this->size = stations.size();
}

vector<string> Stations::createVectorStations(const map<string, vector<Transport>> &mapStations) {
    vector<string> result;
    for (const auto &mapStation: mapStations) {
        string station = mapStation.first;
        result.push_back(station);
    }
    return result;
}

int Stations::getIndexStationInStations(const string &station) const {
    auto it = find(stations.begin(), stations.end(), station);
    if (it == stations.end()) {
        return -1;
    }
    return distance(stations.begin(), it);
}

Stations::~Stations() {
    size = 0;
    stations.clear();
}

Stations Stations::operator=(const Stations &focus) {
    this->stations = focus.stations;
    this->size = focus.size;
    return *this;
}
