#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

#define INF 987654321

vector<pair<int, int>> vec[10002];
int N, M, X;
int MAX = 0;
int W[1002][1002] = { 0, };

void func(int src);

int main() {
	cin >> N >> M >> X;

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
	}

	for (int i = 1; i <= N; i++) {
		func(i);
	}

	for (int i = 1; i <= N; i++) {
		if (MAX < W[i][X] + W[X][i])
			MAX = W[i][X] + W[X][i];
	}

	cout << MAX << endl;

	return 0;
}

void func(int src) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

	q.push({ src, 0 });

	for (int i = 1; i <= N; i++) {
		W[src][i] = INF;
		if (src != i) {
			q.push({ i, INF });
		}
	}
	W[src][src] = 0;

	while (!q.empty()) {
		int y = q.top().first, t = q.top().second;
		q.pop();

		if (t > W[src][y])
			continue;

		for (int i = 0; i < vec[y].size(); i++) {
			int dest = vec[y][i].first;
			int dis = vec[y][i].second;

			if (W[src][dest] > W[src][y] + dis) {
				W[src][dest] = W[src][y] + dis;
				q.push({ dest, W[src][dest] });
			}
		}
	}
}