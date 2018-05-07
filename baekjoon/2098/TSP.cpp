#include<iostream>
using namespace std;

int N;
long long W[17][17] = { 0, };
int bits = 1;
int cur_city = 0;
long long DP[65537] = { 0, };

void dfs(int bis, int cur, long long prev_cost, int cnt);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	dfs(bits, cur_city, 0, 1);

	int t = (1 << N) - 1;
	cout << DP[t] << endl;

	return 0;
}

void dfs(int bis, int cur, long long prev_cost, int cnt) {
	int temp = bis;
	int temp2;

	if (cnt == N) {
		if (W[cur][0] == 0) {
			return;
		}
		if (DP[(1 << N)] != 0) {
			if (DP[(1 << N)] < prev_cost + W[cur][0]) {
				return;
			}
		}
		DP[(1 << N)] = prev_cost + W[cur][0];
		return;
	}

	for (int i = 0; i < N; i++, temp = temp >> 1) {
		temp2 = bis;
		if ((temp & 1) != 1 && W[cur][i] != 0) {
			int t = 1 << i;
			temp2 |= t;
			if (DP[temp2] != 0) {
				if (DP[temp2] < prev_cost + W[cur][i]) {
					return;
				}
			}
			DP[temp2] = prev_cost + W[cur][i];
			dfs(temp2, i, DP[temp2], cnt + 1);
		}
	}
}