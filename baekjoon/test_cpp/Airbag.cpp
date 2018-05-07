#include "Airbag.h"

Airbag::Airbag(Car* car) {
	this->car = car;
}

int Airbag::getCost() {
	return car->getCost() + 10000;
}

string Airbag::getDescription() {
	return car->getDescription() + ", Airbag";
}