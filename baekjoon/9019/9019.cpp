#include <iostream>
#include <string>
#include <queue>
using namespace std;

int T;
int A, B;

int D(int val) {
	return (val * 2) % 10000;
}

int S(int val) {
	return val - 1 >= 0 ? val - 1 : 9999;
}
int L(int val) {
	return (val * 10) % 10000 + val / 1000;
}
int R(int val) {
	return (val / 10) + 1000 * (val % 10);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		int visit[10002] = { 0, };
		scanf("%d%d", &A, &B);

		queue<pair<string, int>> q;
		q.push({ "", A });

		while (!q.empty()) {
			string oper = q.front().first;
			int x = q.front().second;
			q.pop();

			if (x == B) {
				cout << oper << endl;
				break;
			}
			else {
				int t;
				t = D(x);
				if (!visit[t]) {
					visit[t] = 1;
					q.push({ oper + "D", t });
				}
				t = S(x);
				if (!visit[t]) {
					visit[t] = 1;
					q.push({ oper + "S", t });
				}
				t = L(x);
				if (!visit[t]) {
					visit[t] = 1;
					q.push({ oper + "L", t });
				}
				t = R(x);
				if (!visit[t]) {
					visit[t] = 1;
					q.push({ oper + "R", t });
				}
			}

		}
	}

	return 0;
}