#include <iostream>
using namespace std;

int N, M;
int arr[101][101] = { 0, };
int line[101] = { 0, };
int cnt = 0;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;
	}
	line[0] = 1;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (line[i] == 1) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j] == 1) {
						line[j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (line[i] == 1) {
			cnt++;
		}
	}

	cout << cnt - 1 << endl;

	return 0;
}