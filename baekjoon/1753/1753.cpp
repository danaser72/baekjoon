#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vec[20001];
int V, E;
int K;
int u, v, w;
int d[20001] = { 0, };

void DA(int st, int en);

int main() {
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		
		vec[u].push_back({ v,w });
	}
	for (int k = 0; k < V; k++) {
	}

	return 0;
}

void DA(int st, int en) {
	vector <int> Q;

	for (int i = 0; i < V; i++) {
		Q.push_back(i + 1);
	}

	while (!Q.empty()) {
		if (Q.size() == V) {
		}
		else {
			int t = Q.front();

			for (int i = 0; i < V; i++) {

			}
		}
	}
}