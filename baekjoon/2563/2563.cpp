#include <iostream>
using namespace std;

int N, x, y;
bool arr[102][102] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				arr[j][k] = true;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			sum += arr[i][j];
		}
	}

	cout << sum << endl;

	return 0;
}