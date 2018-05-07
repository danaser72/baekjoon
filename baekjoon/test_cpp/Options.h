#pragma once
#include "Car.h"

class Options : public Car {
public:
	virtual int getCost() = 0;
	virtual string getDescription() = 0;
};