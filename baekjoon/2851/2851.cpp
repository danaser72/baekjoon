#include <iostream>
using namespace std;

int mid = 0;
int arr[11] = { 0, };
int ABS(int n) {
	return n < 0 ? -n : n;
}

int main() {
	int num;

	for (int i = 1; i <= 10; i++) {
		cin >> num;

		arr[i] = arr[i - 1] + num;
	}

	for (int i = 1; i <= 10; i++) {
		if (ABS(100 - mid) > ABS(100- arr[i])) {
			mid = arr[i];
		}
		else if (ABS(100 - mid) == ABS(100 - arr[i]) && mid < arr[i]) {
			mid = arr[i];
		}
	}
	cout << mid << endl;

	return 0;
}