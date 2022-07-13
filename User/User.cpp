//
// Created by solod on 05.07.2022.
//

#include "User.h"

User User::operator=(User&focus) {
    this->choose = focus.choose;
    this->endStation= focus.endStation;
    this->userStation = focus.userStation;
    return *this;
}
