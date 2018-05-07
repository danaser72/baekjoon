#include <iostream>
using namespace std;

int n;
int arr[1001] = { 0, };
int box[1001] = { 1, };
int maxs = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		int max_cur = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (max_cur < box[j]) {
					max_cur = box[j];
				}
			}
		}

		box[i] = max_cur + 1;

		if (maxs < box[i]) {
			maxs = box[i];
		}
	}

	cout << maxs << endl;

	return 0;
}