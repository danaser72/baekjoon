#include "Navigation.h"

Navigation::Navigation(Car* car) {
	this->car = car;
}

int Navigation::getCost() {
	return car->getCost() + 20000;
}

string Navigation::getDescription() {
	return car->getDescription() + ", Navigator";
}