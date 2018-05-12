#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[16][16];
int ans[16][1 << 16];
const int INF = 999999999;

int func(int v, int cur);

int main() {
	memset(ans, -1, sizeof(ans));
	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n", func(1, 0));

	return 0;
}

int func(int v, int cur) {
	if (v == (1 << N) - 1) {
		if (arr[cur][0] != 0)
			return arr[cur][0];
		return INF;
	}

	if (ans[cur][v] != -1) {
		return ans[cur][v];
	}

	int ret = INF;

	for (int i = 0; i < N; i++) {
		if (v & (1 << i) || arr[cur][i] == 0)
			continue;

		ret = min(ret, arr[cur][i] + func(v + (1 << i), i));
	}

	return ret;
}