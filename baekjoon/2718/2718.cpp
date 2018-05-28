/*
** reference : http://blog.daum.net/rhaoslikesan/369
				http://joonas-yoon.blogspot.kr/2016/03/2718.html
*/

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