#include <iostream>
using namespace std;

int N;
long long arr[16] = { 3, };

int main() {

	cin >> N;

	if (N % 2 == 1) {
		cout << "0" << endl;
		return 0;
	}

	N = N / 2 - 1;

	if (N == 0) {
		cout << "3" << endl;
		return 0;
	}

	for (int i = 1; i <= N+1; i++) {
		long long sum = arr[i - 1] * 3+2;
		for (int j = i - 2; j >= 0; j--) {
			sum += arr[j] * 2;
		}

		arr[i] = sum;
	}

	cout << arr[N] << endl;

	return 0;
}