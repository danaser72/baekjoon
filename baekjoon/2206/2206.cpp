#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int MOVE[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
char map[1002][1002];
int visit[1002][1002];

int main() {
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	memset(visit, -1, sizeof(visit));
	visit[1][1] = 0;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	vector<pair<int, int>> v;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1,1 }, { 1,0 } });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int route = q.front().second.first;
		int cnt = q.front().second.second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int n = x + MOVE[i][0];
			int m = y + MOVE[i][1];

			if (n > N || n < 1 || m > M || m < 1)
				continue;

			int wall = cnt + (map[n][m] - '0');

			if (wall >= 2)
				continue;

			if (n == N && m == M) {
				v.push_back({ route + 1, cnt });
			}
			else {
				if (visit[n][m] == -1 || visit[n][m] > wall) {
					visit[n][m] = wall;
					q.push({ { n,m }, { route + 1,wall} });
				}
			}
		}
	}

	int pos = -1;

	for (int i = 0; i < v.size(); i++) {
		if (pos == -1)
			pos = i;
		else {
			if (v[pos].first > v[i].first)
				pos = i;
		}
	}

	if (pos == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", v[pos].first);
	}

	return 0;
}