#include <iostream>
#include <string.h>
using namespace std;

int N;
int arr[102];
long long dp[102][22];

unsigned long long func(int x, int sum);

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << func(1, arr[0]) << endl;
	//printf("%lld\n", func(1, arr[0]));

	return 0;
}

unsigned long long func(int x, int sum) {
	if (sum > 20 || sum < 0)
		return 0;

	if (x == N - 1)
		return sum == arr[N - 1];

	if (dp[x][sum] != -1)
		return dp[x][sum];

	unsigned long long ret = 0;

	ret += func(x + 1, sum - arr[x]);
	ret += func(x + 1, sum + arr[x]);

	dp[x][sum] = ret;

	return ret;
}