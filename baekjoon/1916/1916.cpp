#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000000

int n, m;
vector<pair<int, int>> adj[1002];
int val[1002];
int s_Point, e_Point;

struct node {
	int endPoint;
	int dist;
};

struct cmp {
	bool operator () (node x, node y) {
		return x.dist > y.dist;
	}
};

void func();

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int val1, val2, val3;
		cin >> val1 >> val2 >> val3;
		adj[val1].push_back({ val2, val3 });
	}
	cin >> s_Point >> e_Point;

	for (int i = 0; i < n; i++) {
		val[i] = MAX;
	}

	func();

	cout << val[e_Point] << endl;

	return 0;
}

void func() {
	priority_queue <node, vector<node>, cmp> pq;

	pq.push({ s_Point, 0 });

	for (int i = 0; i < n; i++) {
		val[i + 1] = MAX;
		if (i + 1 != s_Point) {
			pq.push({ i + 1, MAX });
		}
	}
	val[s_Point] = 0;

	while (!pq.empty()) {
		int _end = pq.top().endPoint;
		int _dist = pq.top().dist;
		pq.pop();

		if (_dist > val[_end]) {
			continue;
		}

		for (int i = 0; i < adj[_end].size(); i++) {
			int dest = adj[_end][i].first;
			int dis = adj[_end][i].second;

			if (val[dest] > val[_end] + dis) {
				val[dest] = val[_end] + dis;
				pq.push({ dest, val[dest] });
			}
		}
	}
}