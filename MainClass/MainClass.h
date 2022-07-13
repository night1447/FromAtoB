//
// Created by solod on 06.07.2022.
//
#include "string"
#include "vector"
#include "../algorithmDijkstra/AlgorithmDijkstra.h"

class MainClass {
    std::vector<std::string> routeStations;
    std::vector<int> weight;
    vector <Transport> intersectionTransports;
    bool choose;
    double total;
    vector<int> createWeight(AlgorithmDijkstra &algorithmDijkstra);

    vector<int> correctFocusWeight(vector<int> &focusWeight);

    vector <Transport> createIntersectionTransports(Transports &transports, AlgorithmDijkstra &algorithmDijkstra);

    Transport findTransportTo(vector <Transport> &transports, const string &current, const string &next,
                              const int &currentProperty);
    double createTotalSelectionResult();
    void changeTimeInIntersectionTransports(vector<Transport> &result, const vector<string>&stations);

        public:
    MainClass(AlgorithmDijkstra &algorithmDijkstra, Transports &transports);
    double getTotal(){return total;}
    vector<int> getWeight() { return weight; }
    bool getChoose(){return choose;}
    vector <Transport> getIntersectionTransports() { return intersectionTransports; }
    vector <string> getRouteStations() { return routeStations; }
};


