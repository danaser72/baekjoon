#pragma once

#include <string>
using namespace std;

class Car {
protected :
	int cost;
	char* description;
public :
	virtual int getCost() = 0;
	virtual string getDescription() = 0;
};