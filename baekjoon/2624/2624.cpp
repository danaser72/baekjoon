#include <iostream>
#include <string.h>
using namespace std;

int func(int index, int SUM);

int T, k;
int coin[102][2];
int dp[102][10002];


int main() {
	cin >> T >> k;

	for (int i = 0; i < k; i++) {
		cin >> coin[i][0] >> coin[i][1];
	}

	memset(dp, -1, sizeof(dp));
	func(0, T);

	cout << dp[0][T] << endl;

	return 0;
}

int func(int index, int SUM) {
	if (SUM == 0) {
		return 1;
	}

	if (SUM < 0 || index >= k) {
		return 0;
	}

	int ret = dp[index][SUM];
	if (ret != -1)
		return dp[index][SUM];

	ret = 0;

	for (int i = 0; i <= coin[index][1]; i++) {
		ret += func(index + 1, SUM - coin[index][0] * i);
	}

	dp[index][SUM] = ret;

	return ret;
}