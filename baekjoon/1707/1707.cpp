/*
** reference : https://ko.wikipedia.org/wiki/%EC%9D%B4%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int K, V, E;
int color[20002];

bool func(int x, vector<int> adj[], int before);

int main() {
	//cin >> K;
	scanf("%d", &K);

	while (K--) {
		//cin >> V >> E;
		scanf("%d%d", &V, &E);
		memset(color, 0, sizeof(color));
		vector<int> adj[20002];

		for (int i = 0; i < E; i++) {
			int from, to;
			//cin >> from >> to;
			scanf("%d%d", &from, &to);

			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		bool chk;
		for (int i = 1; i <= V; i++) {
			chk = func(i, adj, color[i]);
			if (!chk) {
				printf("NO\n");
				break;
			}
		}

		if (chk) {
			//cout << "YES" << endl;
			printf("YES\n");
		}
	}

	return 0;
}

bool func(int x, vector<int> adj[], int before) {
	bool chk = true;

	for (int i = 0; i < adj[x].size(); i++) {
		int val = before == 1 ? 2 : 1;

		if (color[adj[x][i]]) {
			if (color[adj[x][i]] == before)
				return false;
		}
		else {
			color[adj[x][i]] = val;

			chk = func(adj[x][i], adj, val);
		}
		if (!chk)
			return false;
	}

	return true;
}