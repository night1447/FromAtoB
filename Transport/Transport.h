//
// Created by night on 27.06.2022.
//
#include <cmath>
#include "../Route/Route.h"

class Transport {
    string name;
    string timeStopsInMinute;
    string price;
    string number;
    Route route;
    string currentPosition;
    string beginStation;
    string endStation;
    bool toBegin = false;

    static int convertToNumber(const string &s);

public:
    Transport();

    Transport(string name, string timeStopsInMinute, string number, string price, Route route);

    ~Transport();

    friend ostream &operator<<(ostream &out, const Transport &);

    string getNameTransport() { return name; }

    Transport(const Transport &focus);

    bool operator==(Transport &);

    Transport &operator=(const Transport &focus);

    bool operator>(const Transport &) const;

    bool operator<(const Transport &) const;

    int getFullTimeToPosition(const string &userStation);

    int getIndexStation(const string &focus);

    bool hasStation(const string &);

    void changeCurrentPosition(int &elapsedTime);

    int getPrice() const { return floor(atof(price.c_str()) * 100); }

    int getTime() { return convertToNumber(timeStopsInMinute); }

    string getNumber() { return number; }
};

