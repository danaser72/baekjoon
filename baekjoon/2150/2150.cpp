/*
** ref : http://seungkwan.tistory.com/7
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int V, E;
vector<int> v[10002];
vector<int> rev[10002];
int visit[10002];
int ft[10002];
vector<vector<int>> SCC;
int t = 1;

void func(int m) {
	visit[m] = 1;

	for (int i = 0; i < v[m].size(); i++) {
		if (visit[v[m][i]] == 0) {
			func(v[m][i]);
		}
	}
	ft[t++] = m;
}

void func2(int m, vector<int> & scc) {
	scc.push_back(m);
	visit[m] = 1;

	for (int i = 0; i < rev[m].size(); i++) {
		if (visit[rev[m][i]] == 0)
			func2(rev[m][i], scc);
	}
}

int main() {
	cin >> V >> E;

	int from, to;
	for (int i = 0; i < E; i++) {
		cin >> from >> to;

		v[from].push_back(to);
		rev[to].push_back(from);
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= V; i++) {
		if (visit[i] == 0)
			func(i);
	}

	memset(visit, 0, sizeof(visit));

	for (int i = V; i > 0; i--) {
		if (visit[ft[i]] == 0) {
			vector<int> scc;
			func2(ft[i], scc);
			sort(scc.begin(), scc.end());
			SCC.push_back(scc);
		}
	}

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << endl;

	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << "-1" << endl;
	}

	return 0;
}