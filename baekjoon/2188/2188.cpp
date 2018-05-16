/*
** reference http://jason9319.tistory.com/149
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<int> n_c[202];
int b[202] = { 0, };
int MAX = 0;

int bmatch();
int dfs(int , int[]);

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int t, c;
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> c;
			n_c[i].push_back(c);
		}
	}

	cout << bmatch() << endl;

	return 0;
}

int bmatch() {
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		int selected[202] = { 0, };
		ret += dfs(i, selected);
	}

	return ret;
}

int dfs(int cur, int s[]) {
	if (s[cur])
		return 0;
	s[cur] = 1;

	for (int i = 0; i < n_c[cur].size(); i++) {
		int now = n_c[cur][i];

		if (!b[now] || dfs(b[now], s)) {
			b[now] = cur;
			return 1;
		}
	}

	return 0;
}