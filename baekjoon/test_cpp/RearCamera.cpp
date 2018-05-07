#include "RearCamera.h"

RearCamera::RearCamera(Car* car) {
	this->car = car;
}

int RearCamera::getCost() {
	return car->getCost() + 30000;
}

string RearCamera::getDescription() {
	return car->getDescription() + ", RearCamera";
}