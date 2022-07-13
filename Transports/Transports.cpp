//
// Created by solod on 05.07.2022.
//

#include "Transports.h"


vector<string> Transports::createStations(const string &line, int& positionStation) {
    string stationsTransport = line.substr(positionStation);
    vector<string> stationsVector = getDataFromString(stationsTransport, ',');
    return stationsVector;
}
vector<string> Transports::getDataFromString(const string &line,const char &separator) {
    stringstream stream(line);
    string word;
    vector<string> result;
    while (getline(stream, word, separator)) {
        result.push_back(word);
    }
    return result;
}
Transport Transports::createTransport(const string &line, int& positionStation, const vector<string> &stationsVector) {
    string transport = line.substr(0, positionStation - 1);
    vector<string> transportVector = getDataFromString(transport, ' ');

    Route focusRoute(stationsVector);
    string name = transportVector.at(0),
            number = transportVector.at(1),
            time = transportVector.at(2),
            price = transportVector.at(3);
    Transport focusTransport(name, time, number, price, focusRoute);
    return focusTransport;
}
void Transports::createMapStations(const string &line) {
    int positionStation = line.find(':') + 1;
    vector<string> stationsVector = createStations(line, positionStation);
    Transport focusTransport = createTransport(line, positionStation, stationsVector);
    transports.push_back(focusTransport);
    for (auto &station: stationsVector) {
        auto it = mapStations.find(station);
        if (it == mapStations.end()) {
            vector<Transport> transportsOnStation;
            transportsOnStation.push_back(focusTransport);
            pair<string, vector<Transport>> Pair = make_pair(station, transportsOnStation);
            mapStations.insert(Pair);
        } else {
            it->second.push_back(focusTransport);
        }
    }
}

Transports::~Transports() {
    mapStations.clear();
    transports.clear();
}

int Transports::getIndexStationInStations(const string &station) const {
    return stations.getIndexStationInStations(station);
}
