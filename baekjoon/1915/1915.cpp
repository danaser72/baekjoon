#include <iostream>
#include <functional>
#include <queue>
using namespace std;

typedef struct dp {
	int x;
	int y;
	int len;
}DP;

struct cmp {
	bool operator ()(DP a, DP b) {
		return a.len < b.len;
	}
};

int MAX = 0;
int n, m;
char arr[1002][1002] = { 0, };
priority_queue<DP, vector<DP>, cmp> pq;

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		DP newDP;
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			arr[i][j] = t;

			if (t == '1') {
				if (cnt == 0) {
					newDP.x = i;
					newDP.y = j;
				}
				cnt++;

				if (j == m - 1) {
					newDP.len = cnt;
					pq.push(newDP);
				}
			}
			else if (t == '0' && cnt != 0) {
				newDP.len = cnt;
				pq.push(newDP);
				cnt = 0;
			}
		}
	}

	bool chk = false;

	while (!pq.empty() && !chk) {
		int x = pq.top().x, y = pq.top().y, len = pq.top().len;
		int val = 0;
		pq.pop();

		for (int k = 0; k < len; k++) {
			for (int i = x; i < x + len && !chk; i++) {
				for (int j = y; j < y + len && !chk; j++) {
					if (arr[i][j] == '0')
						chk != chk;
				}
			}
		}
		
		chk != chk;

		if (chk)
			MAX = val;
	}

	printf("%d\n", MAX*MAX);

	return 0;
}