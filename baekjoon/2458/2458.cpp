#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[502];
vector<int> rev[502];
int cnt = 0;

bool func(int pos) {
	queue<int> q;
	q.push(pos);
	int count = 0, rev_count = 0;

	int visit[502];
	memset(visit, 0, sizeof(visit));

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (visit[v[x][i]] == 0 && v[x][i] != pos) {
				visit[v[x][i]] = 1;
				q.push(v[x][i]);
				count++;
			}
		}
	}

	q.push(pos);
	memset(visit, 0, sizeof(visit));

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < rev[x].size(); i++) {
			if (visit[rev[x][i]] == 0 && rev[x][i] != pos) {
				visit[rev[x][i]] = 1;
				q.push(rev[x][i]);
				rev_count++;
			}
		}
	}

	return (count + rev_count + 1) == N;
}

int main() {
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		v[from].push_back(to);
		rev[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		if (func(i)) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}