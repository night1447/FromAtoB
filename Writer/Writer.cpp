//
// Created by solod on 06.07.2022.
//

#include "Writer.h"

//WRITER
void Writer::outputRouteTransports( vector<Transport > &result,vector<string>& routeStations) {

    if (!result.empty()){
        cout << "Чтобы добраться до вашей станции вам нужно сесть на эти виды транспортов: "<<endl;
        for (int i = 0; i < result.size(); ++i) {
            cout << i+1<<")"<<endl;
            cout << result[i];
            cout <<"Время прибытия: "<< result[i].getFullTimeToPosition(routeStations[i])<<" min" << endl;

        }
        cout << "Время прибытия транспортов рассчитано с учетом вашего прибывания на эту станцию!"<<endl;
        cout << "========================"<<endl;
    }
    else{
        cout << "Вы на месте!" << endl;
    }
}
void Writer::outputRouteStations(const vector<string> &routeStations) {
    cout << "========================" << endl;
    cout << "Маршрут будет выглядеть так: " << endl;
    for (int i = 0; i < routeStations.size(); ++i) {
        if (i != routeStations.size() - 1) {
            cout << routeStations[i] << " -> ";
        } else {
            cout << routeStations[i] << " ";
        }
    }
    cout << endl << "========================" << endl;
}
//WRITER
void
Writer::outputMain(MainClass&mainElement) {
    cout << "========================" << endl;
    if (mainElement.getChoose()) {
        cout << "Итого вы заплатите: " << mainElement.getTotal() << " y.e." << endl;
    } else {
        cout << "Итого вы потратите: " << mainElement.getTotal() << " min" << endl;
        cout << "Расхождение может быть +- 5 минут"<<endl;
    }
    vector<Transport> transports = mainElement.getIntersectionTransports();
    vector<string> routeStations = mainElement.getRouteStations();
    outputRouteStations(routeStations);
    outputRouteTransports(transports,routeStations);
}