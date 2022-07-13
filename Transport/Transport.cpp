//
// Created by night on 27.06.2022.
//

#include <sstream>
#include <utility>
#include "Transport.h"

ostream &operator<<(ostream &out,const Transport &focus) {
    out <<"Вид транспорта: "<< focus.name << endl;
    out <<"Номер транспорта: "<< focus.number << endl;
    out<<"Цена проезда: " << focus.price <<" y.e."<< endl;

    return out;
}

int Transport::getFullTimeToPosition(const string &userStation) {
    int indexUser = route.getIndexPosition(userStation) + 1,
            indexCurrent = route.getIndexPosition(currentPosition) + 1,
            indexEnd = route.getSize();
    int currentToEnd = 0,
            userToEnd = 0,
            currentToUser = 0;
    int result = 0;
    if (indexCurrent > indexUser) {
        currentToEnd = indexEnd - indexCurrent;
        userToEnd = indexEnd - indexUser;
    } else if (indexCurrent < indexUser) {
        currentToUser = indexUser - indexCurrent;
    }
    result += (currentToUser + currentToEnd + userToEnd) * convertToNumber(timeStopsInMinute);
    return result;
}

Transport::Transport(string name, string timeStopsInMinute, string number, string price, Route route) :
        name(std::move(name)), timeStopsInMinute(std::move(timeStopsInMinute)), number(std::move(number)), route(route),
        price(std::move(price)) {
    currentPosition = route.getRandomStation();
    beginStation = route.getBeginStation();
    endStation = route.getEndStation();

    if (route.getIndexPosition(currentPosition) == route.getIndexPosition(endStation)) {
        toBegin = true;
    }

}

int Transport::convertToNumber(const string &s) {

    stringstream ss;
    ss << s;
    int k = 0;
    ss >> k;
    return k;

}

bool Transport::operator==(Transport &focus) {
    return this->number == focus.number;
}

bool Transport::hasStation(const string &focus) {
    return route.getIndexPosition(focus) != -1;
}
int Transport::getIndexStation(const string&focus){
    return route.getIndexPosition(focus);
}
Transport::Transport(const Transport &focus) {
    this->name = focus.name;
    this->number = focus.number;
    this->route = focus.route;
    this->timeStopsInMinute = focus.timeStopsInMinute;
    this->price = focus.price;
    this->currentPosition = focus.currentPosition;
    this->endStation = focus.endStation;
    this->beginStation = focus.beginStation;
}

Transport::Transport() {
    this->name = "";
    this->number = "";
    this->price = "";
    this->timeStopsInMinute = "";
    this->currentPosition = "";
    this->endStation = "";
    this->beginStation = "";
}

Transport &Transport::operator=(const Transport &focus) {
    if (this == &focus) {
        return *this;
    }
    this->name = focus.name;
    this->number = focus.number;
    this->route = focus.route;
    this->timeStopsInMinute = focus.timeStopsInMinute;
    this->price = focus.price;
    this->currentPosition = focus.currentPosition;
    this->endStation = focus.endStation;
    this->beginStation = focus.beginStation;
    return *this;
}

bool Transport::operator>(const Transport &focus) const {
    return this->getPrice() > focus.getPrice();
}

bool Transport::operator<(const Transport &focus) const {
    return this->getPrice() < focus.getPrice();
}

Transport::~Transport() {
    this->name = "";
    this->number = "";
    this->price = "";
    this->timeStopsInMinute = "";
    this->currentPosition = "";
    this->endStation = "";
    this->beginStation = "";
    route.clear();
}

void Transport::changeCurrentPosition(int &elapsedTime) {
    int countStation = elapsedTime / convertToNumber(timeStopsInMinute);
    int lastIndex = route.getIndexPosition(currentPosition);
    int size = route.getSize();
    int resultIndex = 0;
    if (toBegin) {
        resultIndex = lastIndex - countStation;
        if (resultIndex <= 0) {
            resultIndex = abs(resultIndex);
            if (resultIndex >= size) {
                resultIndex %= size;
                toBegin = false;
            }
            currentPosition = route.getCurrentStation(resultIndex);
        }
    } else {
        resultIndex = lastIndex + countStation;
        if (resultIndex >= size) {
            resultIndex %= size;
            resultIndex = size - resultIndex - 1 ;
            toBegin = true;
        }
        currentPosition = route.getCurrentStation(resultIndex);
    }
}

