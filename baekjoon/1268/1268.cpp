#include <iostream>
using namespace std;

int N;
int dp[1002][1002] = { 0, };
int val[1002][5] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> val[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (val[j][i] == val[k][i]) {
					dp[j][k] = 1;
					dp[k][j] = 1;
				}
			}
		}
	}

	int cnt[1002] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt[i] += dp[i][j];
		}
	}

	int MAX = 0;
	for (int i = 1; i < N; i++) {
		if (cnt[MAX] < cnt[i]) {
			MAX = i;
		}
	}

	cout << MAX + 1 << endl;

	return 0;
}