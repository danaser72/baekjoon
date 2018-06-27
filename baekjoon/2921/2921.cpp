#include <iostream>
using namespace std;

int N;
int dp[1002][2];
long long cnt = 0;

int main() {
	scanf("%d", &N);

	for (int i = 0; i <= N; i++) {
		long long n = (N - i) + 1;

		cnt += ((i + N) * n / 2) + i * n;
	}

	printf("%lld\n", cnt);

	return 0;
}