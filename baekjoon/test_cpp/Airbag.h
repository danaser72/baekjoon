#pragma once
#include "Options.h"

class Airbag :public Options {
private :
	Car* car;
public:
	Airbag(Car*);
	virtual int getCost();
	virtual string getDescription();
};