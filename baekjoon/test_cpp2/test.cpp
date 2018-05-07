#include <iostream>
using namespace std;

int main()
{
	int row, col;

	cout << "행의 개수: ";
	cin >> row;

	cout << "열의 최대 개수: ";
	cin >> col;


	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}