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
			<< "�⺻ 10000000��" << endl
			<< "1. �� ���� �����" << endl
			<< "2. ��ü ���� ����ϱ�" << endl
			<< "3. �����ϱ�" << endl;
		cin >> check;

		if (check == 3)
			break;
		else if (check == 1) {
			while (1) {
				cout << endl << "====================" << endl
					<< "1. Airbag �߰�(1����)" << endl
					<< "2. Naviagtion �߰�(2����)" << endl
					<< "3. RearCamera �߰�(3����)" << endl
					<< "4. �׸��ϱ�" << endl;
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
		<< "����" << endl
		<< "Option : " << car->getCost() << "��" << endl
		<< "Description : " << car->getDescription() << endl;
}

void App::printAll() {
	list<Car*> temp;
	temp.assign(carList.begin(), carList.end());

	for (int i = 0; !temp.empty(); i++) {
		cout << endl << i + 1 << "��° ����" << endl;
		printCar(temp.front());
		temp.pop_front();
		cout << endl;
	}
}