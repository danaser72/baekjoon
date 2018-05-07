#include <iostream>
using namespace std;

int N;
char arr[66][66];

void fn(int x, int y, int size);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	fn(0, 0, N);
	cout << endl;
	return 0;
}

void fn(int x, int y, int size) {
	char check = arr[x][y];

	for (int i = x; i < size + x; i++) {
		for (int j = y; j < size + y; j++) {
			if (check != arr[i][j]) {
				cout << "(";
				fn(x, y, size / 2);
				fn(x, y + size / 2, size / 2);
				fn(x + size / 2, y, size / 2);
				fn(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << check;
}