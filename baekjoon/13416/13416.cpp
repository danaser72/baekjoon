#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
int arr[1003][3];

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}

		for (int i = 0; i < N; i++) {
			sort(arr[i], arr[i] + 3);
		}
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i][2] >= 0)
				sum += arr[i][2];
		}

		cout << sum << endl;
	}

	return 0;
}