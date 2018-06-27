#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
int cnt;
vector<int> heavy[102];
vector<int> light[102];
int ret[102] = { 0, };

int main() {
	scanf("%d%d", &N, &M);
	//memset(ret, -1, sizeof(ret));

	int big, small;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &big, &small);
		heavy[big].push_back(small);
		light[small].push_back(big);
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int visit[102] = { 0, };

		visit[i] = 1;
		cnt++;

		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int j = 0; j < heavy[x].size(); j++) {
				if (visit[heavy[x][j]] == 0) {
					visit[heavy[x][j]] = 1;
					q.push(heavy[x][j]);
					cnt++;
				}
			}
		}

		q.push(i);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int j = 0; j < light[x].size(); j++) {
				if (visit[light[x][j]] == 0) {
					visit[light[x][j]] = 1;
					q.push(light[x][j]);
					cnt++;
				}
			}
		}

		ret[i] = cnt;
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", N - ret[i]);
	}

	return 0;
}