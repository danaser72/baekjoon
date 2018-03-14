#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int arr[101][101][101] = { 0, };
queue<pair<int, pair<int, int>>> q;

int main() {
	bool c = true;
	cin >> N >> M >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) {
					q.push({ i,{j,k} });
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second.first, z = q.front().second.second;
		int val = arr[x][y][z];

		q.pop();

		if (x > 0) {
			if (arr[x - 1][y][z] == 0) {
				arr[x - 1][y][z] = val + 1;
				q.push({ x - 1 ,{ y, z } });
			}
		}
		if (y > 0) {
			if (arr[x][y - 1][z] == 0) {
				arr[x][y - 1][z] = val + 1;
				q.push({ x ,{ y - 1, z } });
			}
		}
		if (z > 0) {
			if (arr[x][y][z - 1] == 0) {
				arr[x][y][z - 1] = val + 1;
				q.push({ x ,{ y, z - 1 } });
			}
		}

		if (x < H - 1) {
			if (arr[x + 1][y][z] == 0) {
				arr[x + 1][y][z] = val + 1;
				q.push({ x + 1 ,{y, z} });
			}
		}
		if (y < M - 1) {
			if (arr[x][y + 1][z] == 0) {
				arr[x][y + 1][z] = val + 1;
				q.push({ x ,{ y + 1, z } });
			}
		}
		if (z < N - 1) {
			if (arr[x][y][z + 1] == 0) {
				arr[x][y][z + 1] = val + 1;
				q.push({ x ,{ y, z + 1 } });
			}
		}
	}

	int m = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[i][j][k] == 0) {
					cout << "-1" << endl;
					return 0;
				}
				else if (m < arr[i][j][k]) {
					m = arr[i][j][k];
				}
			}
		}
	}
	cout << m - 1 << endl;

	return 0;
}
/*
5 3 1
-1 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1


5 3 2
-1 0 0 0 0
-1 -1 0 1 1
1 0 0 1 1
-1 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

*/