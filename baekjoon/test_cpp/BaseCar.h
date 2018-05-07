#pragma once
#include "Car.h"


class BaseCar : public Car {
public:
	virtual int getCost();
	virtual string getDescription();
};