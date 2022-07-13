//
// Created by solod on 05.07.2022.
//

#include "AlgorithmDijkstra.h"

AlgorithmDijkstra::AlgorithmDijkstra(const bool &choose, Transports &transports, const string &userStation,
                                     const string &endStation)
        : MatrixDijkstra(choose, transports) {
    this->size = transports.getSize();
    this->totalWeight = createTotalWeight(transports, userStation);
    this->route = createOptimalRoute(transports, userStation, endStation);
    this->routeStations = createRouteStations(transports);
}

vector<int> AlgorithmDijkstra::createTotalWeight(const Transports &transports, const string &userStation) {
    int userIndex = transports.getIndexStationInStations(userStation);
    vector<int> weight(size);
    vector<int> checkedStation(size);
    int temp, minIndex, minElement;
    int beginIndex = userIndex;
    for (int i = 0; i < size; ++i) {
        weight[i] = 100000;
        checkedStation[i] = 1;
    }
    weight[beginIndex] = -1;


    do {
        minIndex = 100000;
        minElement = 100000;
        for (int i = 0; i < size; ++i) {
            if (checkedStation[i] == 1 && weight[i] < minElement) {
                minElement = weight[i];
                minIndex = i;
            }
        }
        if (minIndex != 100000) {
            for (int i = 0; i < size; ++i) {
                if (matrixDijkstra[minIndex][i] >= 0) {
                    temp = minElement + matrixDijkstra[minIndex][i];
                    if (temp < weight[i]) {
                        weight[i] = temp;
                    }
                }
            }
            checkedStation[minIndex] = -1;
        }
    } while (minIndex < 100000);
    for (auto &item: weight) {
        item++;
    }
    return weight;
}

vector<int> AlgorithmDijkstra::createOptimalRoute(const Transports &transports, const string &userStation,
                                                  const string &endStation) {
    vector<int> optimalRoute;
    int end = transports.getIndexStationInStations(endStation),
            begin = transports.getIndexStationInStations(userStation);
    optimalRoute.push_back(end + 1);
    int weight = totalWeight[end];
    if (weight == 100001) {
        throw Exception("Нет подходящего транспорта для перемещения в конечную точку!");
    } else {
        while (end != begin) {
            for (int i = 0; i < size; ++i) {
                if (matrixDijkstra[i][end] != 0) {
                    int tmp = weight - matrixDijkstra[i][end];
                    if (tmp == totalWeight[i]) {
                        weight = tmp;
                        end = i;
                        optimalRoute.push_back(i + 1);
                    }
                }
            }
        }
    }
    std::reverse(optimalRoute.begin(), optimalRoute.end());
    return optimalRoute;
}

vector<string> AlgorithmDijkstra::createRouteStations(const Transports &transports) {
    vector<string> result;
    vector<string> stations = transports.getStations();
    for (const int &index: route) {
        result.push_back(stations[index - 1]);
    }
    return result;
}
