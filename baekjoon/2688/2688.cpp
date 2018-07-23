#include <iostream>
#include <string>
using namespace std;

int T;
int N;
long long arr[66][10] = { 0, };

int main() {
	cin >> T;
	
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}

	for (int i = 2; i < 66; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][0] += arr[i - 1][j];
		}

		for (int j = 1; j < 10; j++) {
			arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	while (T--) {
		cin >> N;

		long long sum = 0;

		for (int i = 0; i < 10; i++) {
			sum += arr[N][i];
		}

		cout << sum << endl;
	}
	return 0;
}