#include <iostream>
using namespace std;

int N, M, K;

long long arr[16][16] = { 0, };
long long ans = 0;


void func(int sN, int sM, int dN, int dM);

int main() {
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		arr[i][0] = 1;
	}
	for (int i = 0; i < M; i++) {
		arr[0][i] = 1;
	}

	if (K == 0) {
		func(1, 1, N, M);
	}
	else {
		int n = (K - 1) / M, m = (K - 1) % M;

		func(1, 1, n + 1, m + 1);
		for (int i = 0; i < N; i++) {
			arr[i][m] = arr[n][m];
		}
		for (int i = 0; i < M; i++) {
			arr[n][i] = arr[n][m];
		}
		func(n + 1, m + 1, N, M);
	}

	printf("%lld\n", arr[N - 1][M - 1]);

	return 0;
}

void func(int sN, int sM, int dN, int dM) {
	for (int i = sN; i < dN; i++) {
		for (int j = sM; j < dM; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
}