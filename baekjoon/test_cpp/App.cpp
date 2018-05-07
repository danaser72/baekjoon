#include "App.h"
#include "BaseCar.h"
#include "Airbag.h"
#include "Navigation.h"
#include "RearCamera.h"
#include <iostream>
using namespace std;

void App::menu() {
	int check;
	int data;
	while (1) {
		Car* newCar = new BaseCar();

		cout << endl << "====================" << endl
			<< "기본 10000000원" << endl
			<< "1. 새 견적 만들기" << endl
			<< "2. 전체 견적 출력하기" << endl
			<< "3. 종료하기" << endl;
		cin >> check;

		if (check == 3)
			break;
		else if (check == 1) {
			while (1) {
				cout << endl << "====================" << endl
					<< "1. Airbag 추가(1만원)" << endl
					<< "2. Naviagtion 추가(2만원)" << endl
					<< "3. RearCamera 추가(3만원)" << endl
					<< "4. 그만하기" << endl;
				cin >> data;

				if (data == 1) {
					newCar = new Airbag(newCar);
				}
				else if (data == 2) {
					newCar = new Navigation(newCar);
				}
				else if (data == 3) {
					newCar = new RearCamera(newCar);
				}
				else if (data == 4) {
					cout << endl;
					printCar(newCar);
					carList.push_back(newCar);
					break;
				}
				else {
					cout << "error" << endl;
				}
			}
		}
		else if (check == 2) {
			printAll();
		}
		else {
			cout << "error" << endl;
			continue;
		}
	}
}

list<Car*> App::getList() {
	return carList;
}


void App::printCar(Car* car) {
	cout << "====================" << endl
		<< "견적" << endl
		<< "Option : " << car->getCost() << "원" << endl
		<< "Description : " << car->getDescription() << endl;
}

void App::printAll() {
	list<Car*> temp;
	temp.assign(carList.begin(), carList.end());

	for (int i = 0; !temp.empty(); i++) {
		cout << endl << i + 1 << "번째 견적" << endl;
		printCar(temp.front());
		temp.pop_front();
		cout << endl;
	}
}