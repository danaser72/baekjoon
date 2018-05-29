#include <iostream>
using namespace std;

int N, M;
int dp[42] = { 1, 1, };

int func(int n);

int main() {
	cin >> N >> M;

	func(N);

	int ret = 1;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < M; i++) {
		cin >> t1;

		ret *= dp[t1 - t2 - 1];
		t2 = t1;
	}
	ret *= dp[N - t2];
	cout << ret << endl;

	return 0;
}


int func(int n) {
	if (n < 0)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int ret = 0;

	ret = func(n - 1) + func(n - 2);

	dp[n] = ret;

	return ret;
}