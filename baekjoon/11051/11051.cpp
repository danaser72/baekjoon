#include <iostream>
using namespace std;

int N, K;
int dp[1001][1001] = { 0, };

int main() {
	scanf("%d%d", &N, &K);

	if (K > N / 2) {
		K = N - K;
	}

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	//cout << dp[N][K] << endl;
	printf("%d\n", dp[N][K]);

	return 0;
}