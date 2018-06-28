#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, int>> q;
int visit[100002] = { 0, };

int main() {
	cin >> N >> K;

	q.push({ N, 0 });

	while (!q.empty()) {
		int pos = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (visit[pos] == 0) {
			visit[pos] = 1;

			if (pos == K) {
				cout << sec << endl;
				return 0;
			}
			else {
				if (pos - 1 >= 0) {
					q.push({ pos - 1, sec + 1 });
				}
				if (pos + 1 <= 100000) {
					q.push({ pos + 1, sec + 1 });
				}
				if (pos * 2 <= 100000) {
					q.push({ pos * 2, sec + 1 });
				}
			}
		}
	}
}