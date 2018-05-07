#include <iostream>
using namespace std;

int T;
int N, M, K;
int arr[51][51];
int cnt;

void fn(int x, int y, int ccnt);

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}

		cnt = 1;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					arr[i][j] = cnt;
					fn(i, j, cnt);
				}
			}
		}

		cout << cnt - 1 << endl;
	}
	
	return 0;
}

void fn(int x, int y, int ccnt) {
	if (x > 0) {
		if (arr[x - 1][y] == 1) {
			arr[x - 1][y] = ccnt;
			fn(x - 1, y, ccnt);
		}
	}

	if (y > 0) {
		if (arr[x][y - 1] == 1) {
			arr[x][y - 1] = ccnt;
			fn(x, y - 1, ccnt);
		}
	}

	if (x < M - 1) {
		if (arr[x + 1][y] == 1) {
			arr[x + 1][y] = ccnt;
			fn(x + 1, y, ccnt);
		}
	}

	if (y < N - 1) {
		if (arr[x][y + 1] == 1) {
			arr[x][y + 1] = ccnt;
			fn(x, y + 1, ccnt);
		}
	}
}