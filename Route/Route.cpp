//
// Created by night on 27.06.2022.
//

#include "Route.h"
#include "algorithm"

ostream &operator<<(ostream &out, Route &focus) {

    for (int i = 0; i < focus.size; ++i) {
        out << focus.stations.at(i) << endl;
    }
    return out;
}

string Route::getRandomStation() {
    srand(time(nullptr));
    int indexRandomStation;
    if (size == 1) {
        indexRandomStation = 0;
    } else indexRandomStation = rand() % (size - 1) + 0;
    string randomStation = stations.at(indexRandomStation);
    return randomStation;
}

string Route::getBeginStation() {
    return stations.at(0);
}

string Route::getEndStation() {
    int end = size - 1;
    return stations.at(end);
}

int Route::getIndexPosition(const string &current) {
    int index;
    auto it = find(stations.begin(), stations.end(), current);
    if (it == stations.end()) {
        return -1;
    }
    index = distance(stations.begin(), it);
    return index;
}

int Route::getSize() const {
    return size;
}

Route::Route(const Route &focus) {
    this->stations = focus.stations;
    this->size = focus.size;
}

Route &Route::operator=(const Route &focus) {
    if (this == &focus) return *this;
    this->stations = focus.stations;
    this->size = focus.size;
    return *this;
}

void Route::clear() {
    stations.clear();
    size = 0;
}

string Route::getCurrentStation(int index) {
    return stations.at(index);
}
