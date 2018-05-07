#pragma once
#include "Options.h"

class Navigation :public Options {
private:
	Car* car;
public:
	Navigation(Car*);
	virtual int getCost();
	virtual string getDescription();
};