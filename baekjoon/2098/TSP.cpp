#include <iostream>
using namespace std;

int N;
int W[17][17] = { 0, };
int DP[17][1 << 16] = { 0, };
int INF = 987654321;

int func(int city, int cnt);

int main() {
	cin >> N;
//	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W[i][j];
			//scanf("%d", &W[i][j]);
		}
	}

	cout << func(1, 1) << endl;

	return 0;
}

int func(int city, int cnt) {
	if (cnt == (1 << N) - 1) {
		if (W[city][1] != 0) {
			return W[city][1];
		}
		return INF;
	}

	if (DP[city][cnt] != 0) {
		return DP[city][cnt];
	}

	int ret = INF;

	for (int i = 2; i <= N; i++) {
		if (cnt & (1 << i - 1) || W[city][i] == 0){
			continue;
		}

		int t = W[city][i] + func(i, cnt + (1 << i - 1));

		ret = t < ret ? t : ret;
	}

	DP[city][cnt] = ret;
	// 추가하지 않아서 시간초과가 된 문장

	return ret;
}