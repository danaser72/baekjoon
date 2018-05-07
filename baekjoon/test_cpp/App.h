#pragma once

#include <list>
#include "Car.h"
using namespace std;

class App {
private :
	list<Car*> carList;

public :
	list<Car*> getList();

	void menu();
	void printCar(Car*);
	void printAll();
};