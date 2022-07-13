//
// Created by solod on 06.07.2022.
//

#include "ConsoleReader.h"
#include "set"

std::string ConsoleReader::readChooseRoute(const std::vector<std::string> &chooses) {
    std::string number;
    std::cout << "Как вы хотите добраться?" << std::endl;
    std::cout << "1. " << chooses.at(0) << std::endl;
    std::cout << "2. " << chooses.at(1) << std::endl;
    std::cout << "Выберите номер:" << std::endl;
    std::cin >> number;
    return number;
}

bool findAnswer(const string &answer) {
    vector<string> answers = {"lf", "да", "ДА", "Да","okay","yes","da"};
    set<string> setAnswers(answers.begin(), answers.end());
    for (set<string>::iterator it = setAnswers.begin(); it != setAnswers.end(); it++) {
        if (answer.find(*it) != -1) {
            return true;
        }
    }
    return false;
}

bool ConsoleReader::checkAnswerConsole(const std::string &check) {
    return findAnswer(getStringLowerCase(check));
}
