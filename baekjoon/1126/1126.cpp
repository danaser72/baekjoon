/*
** reference : http://junh0.tistory.com/2
*/

#include <iostream>
using namespace std;

#define MAX 500002
int N;
int arr[52];
int dp[52][MAX] = { 0, };

void func();

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= MAX; i++)
		dp[0][i] = -1;

	func();

	if (dp[N][0] != 0)
		cout << dp[N][0] << endl;
	else
		cout << "-1" << endl;

	return 0;
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX; j++) {
			// 포함이 안된 경우
			dp[i][j] = dp[i - 1][j];

			// 포함되어, 높이차가 j
			// 이전 h1에 포함한 상태(이전 높이차는 j - arr[i])
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][j - arr[i]] + arr[i] ? dp[i][j] : dp[i - 1][j - arr[i]] + arr[i];
			}
			// 이전 h2에 포함하여, h1인 상태(이전 높이차는 arr[i] - j)
			if (j - arr[i] <= 0 && dp[i - 1][arr[i] - j] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][arr[i] - j] + j ? dp[i][j] : dp[i - 1][arr[i] - j] + j;
			}
			// 이전 h2에 포함했지만, h2인 상태 (이전 높이차는 j + arr[i])
			if (j + arr[i] <= MAX && dp[i - 1][j + arr[i]] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][j + arr[i]] ? dp[i][j] : dp[i - 1][j + arr[i]];
			}
		}
	}
}