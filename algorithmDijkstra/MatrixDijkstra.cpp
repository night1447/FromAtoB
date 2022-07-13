//
// Created by solod on 06.07.2022.
//

#include "MatrixDijkstra.h"



MatrixDijkstra::MatrixDijkstra(const bool &choose, const Transports &transports) {
    this->choose = choose;
    matrixDijkstra = createMatrixDijkstra(transports);
}

int
MatrixDijkstra::createWeightTransport(const vector <Transport> &transports, const string &begin, const string &end) {
    vector<int> minimal;
    for (Transport transport: transports) {
        if (transport.hasStation(end)) {
            int counter = abs(transport.getIndexStation(begin) - transport.getIndexStation(end));
            minimal.push_back(getWeightCurrentChoose(transport, begin, counter));
        }
    }
    if (minimal.empty()) {
        return -1;
    } else {
        return *min_element(minimal.begin(), minimal.end());
    }
}

int MatrixDijkstra::getWeightCurrentChoose(Transport &transport, const string &userStation, const int &counter) {
    if (choose) {
        return transport.getPrice();
    } else {
        return transport.getFullTimeToPosition(userStation) + transport.getTime() * counter;
    }
}
vector <vector<int>> MatrixDijkstra::createMatrixDijkstra(const Transports &allTransports) {
    Transports transports = allTransports;
    vector <string> stations = transports.getStations();
    map <string, vector<Transport>> mapStations = transports.getMap();
    this->size = transports.getSize();

    vector <vector<int>> matrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            string begin = stations.at(i),
                    end = stations.at(j);
            auto itemBegin = mapStations.find(begin)->second;
            if (begin == end) {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = createWeightTransport(itemBegin, begin, end);
            }
        }
    }
    return matrix;
}