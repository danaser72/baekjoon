#include <iostream>
using namespace std;

int main()
{
	int row, col;

	cout << "���� ����: ";
	cin >> row;

	cout << "���� �ִ� ����: ";
	cin >> col;


	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}