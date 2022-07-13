//
// Created by solod on 05.07.2022.
//
#include "vector"
#include "algorithm"
#include "map"
#include "string"
#include "MatrixDijkstra.h"

class AlgorithmDijkstra : public MatrixDijkstra {
    std::vector<int> route;
    std::vector<std::string> routeStations;
    std::vector<int> totalWeight;

    vector<int>    createTotalWeight(const Transports &transports,
                                  const string &userStation);

    vector<int>    createOptimalRoute(const Transports &transports,
                                   const string &userStation,
                                   const string &endStation);

    vector<string> createRouteStations(const Transports &);

public:
    AlgorithmDijkstra(const bool &choose, Transports &transports, const string &userStation, const string &endStation);

    vector<string> getRouteStations() { return routeStations; }

    vector<int> getTotalWeight() { return totalWeight; }

    vector<int> getRoute() { return route; }

    bool getChoose() { return choose; }
};
