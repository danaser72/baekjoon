#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int t[502];
int ans[502];
vector<int> v[502];
queue<int> q;
int approach[502];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> t[i];

		int build;
		int cnt = 0;

		while (1) {
			cin >> build;

			if (build == -1) break;

			v[build - 1].push_back(i);
			cnt++;
		}
		if (cnt == 0) {
			q.push(i);
		}
		else {
			approach[i] = cnt;
		}
		ans[i] = t[i];
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < v[num].size(); i++) {
			int next = v[num][i];

			if (ans[next] < ans[num] + t[next])
				ans[next] = ans[num] + t[next];

			approach[next] --;

			if (approach[next] == 0)
				q.push(next);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}