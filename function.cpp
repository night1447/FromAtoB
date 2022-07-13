//
// Created by solod on 06.07.2022.
//
#include "function.h"
Transports initTransportsFromFile(const string&path) {
    Transports transports;
    TransportsReader transportsReader(path);
    vector<string> lines = transportsReader.readInfoTransports();
    for (const string &line: lines) {
        transports.createMapStations(line);
    }
    transports.initStations();
    return transports;
}