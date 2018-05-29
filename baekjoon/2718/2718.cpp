/*
** reference : http://blog.daum.net/rhaoslikesan/369
				http://joonas-yoon.blogspot.kr/2016/03/2718.html
*/

#define bitmask


#ifdef bitmask

#include <iostream>
using namespace std;

int T;
int N;
int dp[1002][5];

void func();

int main() {
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = -1;
		}
	}

	cin >> T;

	while (T--) {
		cin >> N;

		func();

		cout << dp[N][0] << endl;
	}

	return 0;
}

void func() {
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 0;
	dp[0][4] = 0;

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			dp[i][0] = 1;
		}
		else {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 2][0];
		}
		dp[i][1] = dp[i - 1][0] + dp[i - 1][4];
		dp[i][2] = dp[i - 1][3];
		dp[i][3] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][4] = dp[i - 1][0] + dp[i - 1][1];
	}
}

#endif

#ifdef DP


#include <iostream>
using namespace std;

int T;
int N;
int dp[1002] = { 1, 1, 5, };
int k[2] = { 3, 2 };

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		if (dp[N] == 0) {
			for (int i = 1; i <= N; i++) {
				if (dp[i] == 0) {
					dp[i] = dp[i - 1] + 4 * dp[i - 2];

					for (int j = 3; j <= i; j++) {
						dp[i] += k[j % 2] * dp[i - j];
					}
				}
			}

		}
		cout << dp[N] << endl;
	}

	return 0;
}

#endif