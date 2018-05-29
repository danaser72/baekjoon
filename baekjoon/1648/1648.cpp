// https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1648


#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;

int dp[15][15][1 << 14] = { 0, };
int func(int x, int y, int status);

int main() {
	//cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);

	if (N % 2 == 1 && M % 2 == 1) {
		printf("0\n");
	}
	else {
		//cout << func(0, 0, 0) << endl;
		printf("%d\n", func(0, 0, 0));
	}

	return 0;
}

int func(int x, int y, int state) {
	if (x == N) {
		return state == 0;
	}
	if (y == M) {
		return func(x + 1, 0, state);
	}
	if (y > M)
		return 0;

	if (dp[x][y][state] != -1)
		return dp[x][y][state];

	int ret = 0;

	if (state & 1) {
		int st = state;
		st = st >> 1;
		//st = st | 0;
		//st = st & ((1 - M) - 1);

		ret += func(x, y + 1, st);
	}
	else {
		int st = state;
		st = st >> 1;
		st = st | (1 << (M - 1));
		//st = st & ((1 - M) - 1);

		ret += func(x, y + 1, st);

		if (!(state & (1 << 1))) {
			st = state;
			st = st >> 2;
			ret += func(x, y + 2, st);
		}
	}
	ret %= 9901;
	dp[x][y][state] = ret;

	return ret;
}