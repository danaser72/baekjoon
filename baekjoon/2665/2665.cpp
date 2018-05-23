#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int dp[53][53];
int MOVE[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

void func(queue<pair<int, int>> q, vector<vector<char>> map);

int main() {
	vector<vector<char>> map;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<char> element;
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			element.push_back(temp);

			dp[i][j] = -1;
		}
		map.push_back(element);
	}

	queue<pair<int, int>> q;

	dp[0][0] = 0;
	q.push({ 0,0 });
	func(q, map);

	cout << dp[N - 1][N - 1] << endl;;

	return 0;
}

void func(queue<pair<int, int>> q, vector<vector<char>> map) {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n = x + MOVE[i][0], m = y + MOVE[i][1];

			if (n >= 0 && n < N && m >= 0 && m < N) {
				if (map[n][m] == '0') {
					map[n][m] = '2';
					q.push({ n,m });

					int t1, t2;
					for (int j = 0; j < 4; j++) {
						int t1 = n + MOVE[j][0], t2 = m + MOVE[j][1];

						if (t1 >= 0 && t1 < N && t2 >= 0 && t2 < N) {
							if (dp[t1][t2] != -1) {
								if (dp[n][m] != -1) {
									dp[n][m] = dp[t1][t2] + 1 < dp[n][m] ? dp[t1][t2] + 1 : dp[n][m];
								}
								else {
									dp[n][m] = dp[t1][t2] + 1;
								}
							}
						}
					}

					/*if (dp[n][m] != -1) {
						dp[n][m] = dp[x][y] + 1 < dp[n][m] ? dp[x][y] + 1 : dp[n][m];
					}
					else {
						dp[n][m] = dp[x][y] + 1;
					}*/
				}
				else if (map[n][m] == '1') {
					map[n][m] = '2';
					q.push({ n,m });

					int t1, t2;
					for (int j = 0; j < 4; j++) {
						int t1 = n + MOVE[j][0], t2 = m + MOVE[j][1];

						if (t1 >= 0 && t1 < N && t2 >= 0 && t2 < N) {
							if (dp[t1][t2] != -1) {
								if (dp[n][m] != -1) {
									dp[n][m] = dp[t1][t2] + 1 < dp[n][m] ? dp[t1][t2] + 1 : dp[n][m];
								}
								else {
									dp[n][m] = dp[t1][t2];
								}
							}
						}
					}
					/*if (dp[n][m] != -1) {
						dp[n][m] = dp[x][y] < dp[n][m] ? dp[x][y] : dp[n][m];
					}
					else {
						dp[n][m] = dp[x][y];
					}*/
				}
			}
		}
	}
}