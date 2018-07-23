#include <iostream>
#include <string.h>
using namespace std;

int T, N;
int score[100002][2];
int dp[100002][2];
int _MAX;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		_MAX = 0;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &score[j][i]);
			}
		}

		for (int i = 0; i < N; i++) {
			if (i == 0) {
				dp[i][0] = score[i][0];
				dp[i][1] = score[i][1];
			}
			else if (i == 1) {
				dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1] + score[i][0]);
				dp[i][1] = MAX(dp[i - 1][0] + score[i][1], dp[i - 1][1]);
			}
			else {
				dp[i][0] = MAX(MAX(dp[i - 1][0], dp[i - 1][1] + score[i][0]), dp[i - 2][0] + score[i][0]);
				dp[i][1] = MAX(MAX(dp[i - 1][0] + score[i][1], dp[i - 1][1]), dp[i - 2][1] + score[i][1]);
			}
		}

		cout << MAX(dp[N - 1][0], dp[N - 1][1]) << endl;
	}

	return 0;
}