#include <iostream>
using namespace std;

int A = 5 * 60, B = 1 * 60, C = 10;
int arr[3] = { 0, };
int T;

int main() {
	cin >> T;

	arr[0] += T / A;
	T %= A;

	arr[1] += T / B;
	T %= B;

	arr[2] += T / C;
	T %= C;
	
	if (T) {
		cout << "-1" << endl;
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}