#include <iostream>
#include <queue>
using namespace std;

int n, m;
char arr[1004][1004] = { 0, };
int MAX = 0;
queue<pair<int, int>> q;

int main() {
	//cin >> n >> m;
	scanf("%d%d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cin >> arr[i][j];
			scanf("%1d", &arr[i][j]);

			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		int dist = n - x > n - y ? n - x : n - y;

		for (int k = 0; k < dist; k++) {
			bool chk = false;
			for (int i = x; i <= x + k + 1; i++) {
				if (arr[i][y + k + 1] != 1) {
					chk = true;
					break;
				}
			}
			if (!chk) {
				for (int i = y; i <= y + k + 1; i++) {
					if (arr[x + k + 1][i] != 1) {
						chk = true;
						break;
					}
				}
			}

			if (chk) {
				MAX = (k + 1) > MAX ? (k + 1) : MAX;
				break;
			}
		}
	}

	cout << MAX * MAX << endl;

	return 0;
}