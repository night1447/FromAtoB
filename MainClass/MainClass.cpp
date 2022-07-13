//
// Created by solod on 06.07.2022.
//

#include "MainClass.h"

MainClass::MainClass(AlgorithmDijkstra &algorithmDijkstra,Transports&transports) {
    this->routeStations = algorithmDijkstra.getRouteStations();
    this->weight = createWeight(algorithmDijkstra);
    this->intersectionTransports = createIntersectionTransports(transports, algorithmDijkstra);
    this->total = createTotalSelectionResult();
}

vector<int> MainClass::createWeight(AlgorithmDijkstra &algorithmDijkstra) {
    vector<int> focusWeight;
    vector<int> route = algorithmDijkstra.getRoute();
    vector<int> totalWeight = algorithmDijkstra.getTotalWeight();
    for (int i = 0; i < route.size(); i++) {
        focusWeight.push_back(totalWeight[route[i] - 1]);
    }
    focusWeight = correctFocusWeight(focusWeight);
    return focusWeight;
}

vector<int> MainClass::correctFocusWeight(vector<int> &focusWeight) {
    vector<int> result = focusWeight;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = i + 1; j < result.size(); ++j) {
            result[j] -= abs(result[i]);
        }
    }
    return result;
}

vector <Transport> MainClass::createIntersectionTransports(Transports &transports,AlgorithmDijkstra&algorithmDijkstra) {
    int index = 0;
    vector<Transport> result;
    map<string,vector<Transport>> mapStations = transports.getMap();

    int size = algorithmDijkstra.getRoute().size();
    this->choose = algorithmDijkstra.getChoose();
    while (true) {
        int currentIndex = index;
        int nextIndex = index + 1;
        if (nextIndex > size - 1) {
            break;
        }
        int currentProperty = weight[nextIndex];
        string current = routeStations[currentIndex];
        string next = routeStations[nextIndex];
        vector<Transport> focusTransports = mapStations.find(current)->second;
        Transport transport = findTransportTo(focusTransports, current, next, currentProperty);
        result.push_back(transport);
        index++;
    }
    if(choose) changeTimeInIntersectionTransports(result, routeStations);
    return result;
}
Transport
MainClass::findTransportTo(vector<Transport> &transports, const string &current, const string &next, const int &currentProperty) {
    for (Transport &transport: transports) {
        if (transport.hasStation(next)) {
            if (choose) {
                if (transport.getPrice() == currentProperty) {
                    return transport;
                }
            } else {
                int counter = abs(transport.getIndexStation(current) - transport.getIndexStation(next));
                if (transport.getFullTimeToPosition(current) + transport.getTime()*counter == currentProperty) {
                    return transport;
                }
            }
        }

    }
}

double MainClass::createTotalSelectionResult() {
    int result = 0;
    if (!choose) {
        int countNegative = count_if(weight.begin(), weight.end(), [](int &item) {
            return item < 0;
        });
        if (countNegative == 0) {
            for (int &item: weight) {
                result += item;
            }
        }
    } else {
        for (int &item: weight) {
            result += item;
        }
    }
    return result/100.0;
}
void MainClass::changeTimeInIntersectionTransports(vector<Transport> &result, const vector<string>&stations) {
    int index = 0;
    for (int i = 0; i < result.size(); ++i) {
        int timeTo = result[i].getFullTimeToPosition(stations[index]) +
                     result[i].getTime();
        for (int j = i + 1; j < result.size(); ++j) {
            result[j].changeCurrentPosition(timeTo);
        }
        index++;
    }
}