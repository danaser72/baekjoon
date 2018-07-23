#include <iostream>
using namespace std;

int arr[2][2] = { 0, };

int main() {
	int cnt = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	int a = arr[0][0] * arr[1][1] + arr[0][1] * arr[1][0], b = arr[1][0] * arr[1][1];

	for (int i = 0; i < 3; i++) {
		int t = arr[0][1];
		arr[0][1] = arr[0][0];
		arr[0][0] = arr[1][0];
		arr[1][0] = arr[1][1];
		arr[1][1] = t;

		int c = arr[0][0] * arr[1][1] + arr[0][1] * arr[1][0], d = arr[1][0] * arr[1][1];

		if (a * d < b * c) {
			cnt = i + 1;
			a = c;
			b = d;
		}
	}

	cout << cnt << endl;

	return 0;
}