#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int MOVE[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int map[302][302] = { 0, };
int visit[302][302];
int cnt = 0;

int main() {
	queue<pair<int, int>> q;
	memset(visit, -1, sizeof(visit));
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] != 0) {
				q.push({ i,j });
				visit[i][j] = cnt;
			}
		}
	}

	bool chk;
	queue<pair<int, int>> age;
	while (1) {
		chk = false;
		// Melting iceberg

		int temp[302][302];
		memcpy(temp, map, sizeof(map));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] != 0) {
					int count = 0;

					for (int k = 0; k < 4; k++) {
						int x = i + MOVE[k][0];
						int y = j + MOVE[k][1];

						if (x <= N && x > 0 && y <= M && y > 0) {
							if (map[x][y] == 0)
								count++;
						}
					}
					temp[i][j] = map[i][j] - count;
					if (temp[i][j] < 0)
						temp[i][j] = 0;
				}
			}
		}

		memcpy(map, temp, sizeof(map));

		cnt++;

		// Checking iceberg
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visit[i][j] == cnt - 1 && map[i][j]) {
					if (chk) {
						printf("%d\n", cnt);
						return 0;
					}
					chk = true;

					queue<pair<int, int>> t2;
					t2.push({ i,j });
					visit[i][j] = cnt;

					while (!t2.empty()) {
						int x = t2.front().first;
						int y = t2.front().second;

						t2.pop();

						for (int k = 0; k < 4; k++) {
							int n = x + MOVE[k][0];
							int m = y + MOVE[k][1];

							if (n <= N && n > 0 && m <= M && m > 0 && visit[n][m] == cnt - 1 && map[n][m]) {
								t2.push({ n,m });
								visit[n][m] = cnt;
							}
						}
					}
				}
			}
		}

		if (!chk) {
			printf("0\n");
			return 0;
		}
	}
}