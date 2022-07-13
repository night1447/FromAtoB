//
// Created by solod on 06.07.2022.
//
#include "../MainClass/MainClass.h"

class Writer {
    void outputRouteStations(const vector<string> &routeStations);
    void outputRouteTransports(vector<Transport > &result, vector<string>& routeStations);
        public:
    Writer(){}
    void outputMain(MainClass&mainElement);
};
