//
// Created by solod on 05.07.2022.
//

#include "string"
#include "vector"
class User {
protected:
    std::string userStation;
    std::string endStation;
    bool choose;
    std::vector<std::string> chooses = {"быстрее", "дешевле"};
public:
    User(std::string userStation, std::string endStation, bool choose) :
     userStation(userStation), endStation(endStation), choose(choose){}

    User() : userStation(""), endStation(""), choose(false){}
    User operator = (User&);
    std::vector<std::string> getChooses(){return chooses;}
    bool getChoose(){return choose;}
    std::string getUserStation() {return userStation;}
    std::string getEndStation() {return endStation;}
};


