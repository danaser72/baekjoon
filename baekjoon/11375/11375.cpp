#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> work[1002];
int b[1002];

int bmatch();
int dfs(int here, int []);

int main() {
	int wc, w;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> wc;
		for (int j = 0; j < wc; j++) {
			cin >> w;
			work[i].push_back(w);
		}
	}

	cout << bmatch() << endl;

	return 0;
}

int bmatch() {
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		int visited[1002] = { 0, };
		ret += dfs(i, visited);
	}

	return ret;
}


int dfs(int here, int v[]) {
	if (v[here])
		return 0;

	v[here] = 1;

	for (int i = 0; i < work[here].size(); i++) {
		int now = work[here][i];
		if (!b[now] || dfs(b[now], v)) {
			b[now] = here;
			return 1;
		}
	}

	return 0;
}