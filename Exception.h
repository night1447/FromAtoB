#pragma once
#include <iostream>
using namespace std;
class Exception {
	string str;
public:
	Exception(string str) {
		this->str = str;
	}
	string GetException() {
		return str;
	}
};