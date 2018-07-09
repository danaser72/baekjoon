/*
** ref : http://wootool.tistory.com/72
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int visit[10002] = { 0, };
vector<int> v[10002];
vector<int> com;
int MAX = 0;

int main() {
	cin >> N >> M;

	int A, B;

	for (int i = 0; i < M; i++) {
		cin >> B >> A;

		v[A].push_back(B);
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		memset(visit, 0, sizeof(visit));

		queue<int> q;
		q.push(i);
		visit[i] = 1;
		cnt++;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int j = 0; j < v[x].size(); j++) {
				if (visit[v[x][j]] == 0) {
					visit[v[x][j]] = 1;
					q.push(v[x][j]);
					cnt++;
				}
			}
		}

		if (MAX < cnt) {
			vector<int> t;
			t.push_back(i);
			MAX = cnt;
			com = t;
		}
		else if (MAX == cnt) {
			com.push_back(i);
		}
	}

	sort(com.begin(), com.end());

	for (int i = 0; i < com.size(); i++)
		cout << com[i] << " ";
	cout << endl;

	return 0;
}