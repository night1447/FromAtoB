//
// Created by night on 27.06.2022.
//
#include "vector"
#include "iostream"
#include "../Exception.h"

using namespace std;

class Route {
    vector<string> stations;
    int size;
public:
    string getRandomStation();

    string getCurrentStation(int index);

    int getIndexPosition(const string &);

    string getBeginStation();

    string getEndStation();

    Route() : size(0) {}

    Route(const Route &);

    explicit Route(const vector<string> &stations) : stations(stations), size(stations.size()) {}

    friend ostream &operator<<(ostream &, Route &);

    int getSize() const;

    Route &operator=(const Route &);

    void clear();

};

