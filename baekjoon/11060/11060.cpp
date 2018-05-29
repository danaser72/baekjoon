#include <iostream>
using namespace std;

int N;
int dp[1002] = { 0, };

int main() {
	//cin >> N;
	scanf("%d", &N);

	dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		int t;
		//cin >> t;
		scanf("%d", &t);

		if (dp[i] != 0) {
			for (int j = i; j <= i + t && j <= N; j++) {
				if (dp[j] == 0 || dp[j] > dp[i] + 1)
					dp[j] = dp[i] + 1;
			}
		}
	}
	if (dp[N] == 0)
		printf("-1\n");
	else
		printf("%d\n", dp[N] - 1);

	return 0;
}