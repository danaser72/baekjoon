#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N;
int MOVE[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int arr[101][101];
int map[101][101] = { 0, };
int ans = 987654321;

vector<queue<pair<int, pair<int, int>>>> v;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(map, -1, sizeof(map));

	int chk = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1 && map[i][j] == -1) {
				queue<pair<int, int>> t;
				queue<pair<int, pair<int, int>>> t2;

				t.push({ i,j });
				t2.push({ 0,{ i,j } });
				map[i][j] = chk;
				while (!t.empty()) {
					int x = t.front().first;
					int y = t.front().second;
					t.pop();

					for (int i = 0; i < 4; i++) {
						int n = x + MOVE[i][0];
						int m = y + MOVE[i][1];

						if (n <= N && n >= 1 && m <= N && m >= 1 && map[n][m] == -1 && arr[n][m] == 1) {
							map[n][m] = chk;
							t.push({ n,m });
							t2.push({ 0, { n,m } });
						}
					}
				}

				v.push_back(t2);
				chk++;
			}
		}
	}

	for (int i = 1; i < v.size(); i++) {
		queue<pair<int, pair<int, int>>> q = v[i];
		int _map[101][101];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				_map[i][j] = map[i][j];
		}

		while (!q.empty()) {
			int x = q.front().second.first;
			int y = q.front().second.second;
			int len = q.front().first;

			q.pop();

			if (len < ans) {
				for (int j = 0; j < 4; j++) {
					int n = x + MOVE[j][0];
					int m = y + MOVE[j][1];

					if (n <= N && n >= 1 && m <= N && m >= 1 && _map[n][m] != -2) {
						if (_map[n][m] == -1) {
							_map[n][m] = -2;
							q.push({ len + 1, {n, m} });
						}
						else if (_map[n][m] != i) {
							if (ans > len)
								ans = len;
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}