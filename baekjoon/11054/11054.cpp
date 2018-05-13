#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1002] = { 0, };
int dp1[1002] = { 0, };
int dp2[1002] = { 0, };
int MAX = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp1[i] = dp1[j] + 1 > dp1[i] ? dp1[j] + 1 : dp1[i];
			}
		}
		if (dp1[i] == 0)
			dp1[i] = 1;
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp2[i] = dp2[j] + 1 > dp2[i] ? dp2[j] + 1 : dp2[i];
			}
		}
		if (dp2[i] == 0)
			dp2[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (dp1[i] + dp2[i] > MAX)
			MAX = dp1[i] + dp2[i];
	}

	cout << MAX - 1 << endl;

	return 0;
}