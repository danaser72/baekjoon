#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 3000000

struct node {
	int endPoint;
	int dist;
};

struct cmp {
	bool operator () (node x, node y) {
		return x.dist > y.dist;
	}
};


void DA(int K);

vector<pair <int, int>> adj[20001];
int V, E;
int K;
int u, v, w;

int main() {
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
	}

	DA(K);

	return 0;
}

void DA(int K) {
	int d[20001];
	priority_queue <node, vector<node>, cmp> pq;
	
	pq.push({ K, 0 });
	for (int i = 0; i < V; i++) {
		d[i + 1] = MAX;
		if (i + 1 != K)
			pq.push({ i + 1, MAX });
	}

	d[K] = 0;

	while (!pq.empty()) {
		int _end = pq.top().endPoint;
		int _dist = pq.top().dist;
		pq.pop();

		if (_dist > d[_end]) {
			continue;
		}

		for (int i = 0; i < adj[_end].size(); i++) {
			int dest = adj[_end][i].first;		// Destination
			int dis = adj[_end][i].second;		// Distance to '_end -> i'

			if (d[dest] > d[_end] + dis) {
				d[dest] = d[_end] + dis;
				pq.push({dest, d[dest]});
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (d[i + 1] == MAX)
			cout << "INF" << endl;
		else {
			cout << d[i + 1] << endl;
		} 
	}
}