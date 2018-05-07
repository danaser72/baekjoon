#include <iostream>
using namespace std;

int N;
int maxs = 0;
int arr[1001] = { 0, };
int big[1001] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		big[i] = arr[i];
	}

	for (int i = 1; i < N; i++) {
		int max_cur = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (max_cur < big[j]) {
					max_cur = big[j];
				}
			}
		}
		big[i] = max_cur + arr[i];

		if (big[i] > maxs) {
			maxs = big[i];
		}
	}

	cout << maxs << endl;

	return 0;
}