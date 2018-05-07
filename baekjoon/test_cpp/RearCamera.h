#pragma once
#include "Options.h"

class RearCamera :public Options {
private:
	Car* car;
public:
	RearCamera(Car*);
	virtual int getCost();
	virtual string getDescription();
};