//
// Created by night on 06.07.2022.
//

#include "UserReader.h"
string UserReader::readStation(const bool &isUserStation, const std::map<string, vector<Transport> > &mapStations) {
    string station;
    string number;
    string name;
    int counterExit = 0;
    int exits = 3;
    if (isUserStation) name = "текущую";
    else name = "конечную";

    cout << "Введите " << name << " станцию: " << endl;
    if (!isUserStation) cin.ignore();
    getline(cin, station);
    if (mapStations.find(station) != mapStations.end()) {
        return station;
    } else {
        while (true) {
            string check;
            vector<string> variants;
            //Make variants of stations
            for (const auto &mapStation: mapStations) {
                if (mapStation.first == station || mapStation.first.find(station) != -1)
                    variants.push_back(mapStation.first);
            }

            for (int i = 0; i < variants.size(); ++i) {
                cout << "Вариант " << i + 1 << ": " << variants[i] << endl;
            }
            if (variants.empty()) {
                cout << "Попробуйте ввести ещё раз вашу станцию" << endl;
                cin >> station;
                counterExit++;
            } else if (variants.size() == 1) {
                cout << "Это ваша станция?(да/нет)" << endl;
                cin >> check;
                getStringLowerCase(check);
                if (checkAnswerConsole(check)) {
                    station = variants[0];
                    return station;
                } else {
                    cout << "Попробуйте ввести ещё раз вашу станцию" << endl;
                    cin >> station;
                    counterExit++;
                }
            } else {
                cout << "Из предложенных вариантов есть, который верен?(да/нет)" << endl;
                cin >> check;
                //Checker answer in variant
                if (checkAnswerConsole(check)) {
                    while (true) {
                        check = "";
                        cout << "Введите номер его:" << endl;
                        cin >> number;
                        if (convertToNumber(number) > 0 && convertToNumber(number) <= variants.size()) {
                            cout << "Вы уверены, в выборе " << convertToNumber(number) << "?(да/нет)" << endl;
                            cin >> check;
                            if (checkAnswerConsole(check)) {
                                station = variants[convertToNumber(number) - 1];
                                return station;
                            }
                        } else {
                            cout << "Введена неверная позиция, попробуйте ещё раз" << endl;
                            if (isUserStation) {
                                if (counterExit == exits) {
                                    cout << "Хотите выйти?(да/нет)" << endl;
                                    cin >> check;
                                    if (checkAnswerConsole(check)) {
                                        cout << "Сожалеем, что не смогли найти вашу станцию" << endl;
                                        break;
                                    } else {
                                        counterExit = 0;
                                        exits--;
                                    }
                                }
                            }
                            counterExit++;
                            if (!exits) {
                                throw Exception("К сожалению, программа должна остановить свою работу");
                            }
                        }

                    }
                } else {
                    cout << "Попробуйте ввести ещё раз вашу станцию" << endl;
                    cin >> station;
                    counterExit++;
                }
            }
            //Controller exit
            if (counterExit == exits) {
                cout << "Хотите выйти?(да/нет)" << endl;
                cin >> check;
                if (checkAnswerConsole(check)) {
                    cout << "Сожалеем, что не смогли найти вашу станцию" << endl;
                    break;
                } else {
                    counterExit = 0;
                    exits--;
                }
            }
            if (!exits) {
                throw Exception("К сожалению, программа должна остановить свою работу");
            }
        }
    }
}

bool UserReader::readUserChooseRoute() {
    vector<string> chooses = {"быстрее", "дешевле"};
    while (true) {
        string chooseNumber = readChooseRoute(chooses);
        if (convertToNumber((chooseNumber)) > 0 && convertToNumber(chooseNumber) <= chooses.size()) {
            return convertToNumber(chooseNumber) - 1; // yes - cheaper, no - faster
        } else {
            cout << "Неверно введен номер, попробуйте еще раз" << endl;
        }
    }
}

