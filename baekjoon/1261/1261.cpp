#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int MOVE[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
char map[102][102];
int visit[102][102];

int main() {
	//cin >> N >> M;
	scanf("%d%d", &M, &N);

	memset(visit, -1, sizeof(visit));
	visit[1][1] = 0;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1,1 }, 0 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int n = x + MOVE[i][0];
			int m = y + MOVE[i][1];

			if (n > N || n < 1 || m > M || m < 1)
				continue;

			int wall = cnt + (map[n][m] - '0');
			if (visit[n][m] == -1 || visit[n][m] > wall) {
				visit[n][m] = wall;
				q.push({ { n,m }, wall });
			}
		}

	}

	printf("%d\n", visit[N][M]);

	return 0;
}