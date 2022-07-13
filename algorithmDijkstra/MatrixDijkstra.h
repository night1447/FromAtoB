//
// Created by solod on 06.07.2022.
//
#include "../Transports/Transports.h"

class MatrixDijkstra {
protected:
    vector<vector<int>> matrixDijkstra;
    bool choose;
    int size;

    int createWeightTransport(const vector<Transport> &transports, const string &begin,
                              const string &end);

    int getWeightCurrentChoose(Transport &transport, const string &userStation, const int &counter);

    vector<vector<int>> createMatrixDijkstra(const Transports &);

public:
    MatrixDijkstra(const bool &choose, const Transports &);
};