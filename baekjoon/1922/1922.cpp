#include <iostream>
using namespace std;

int N, M;
int arr[1001][1001] = { 0, };
int visit[1001] = { 0, };
int costs = 0;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		arr[x - 1][y - 1] = cost;
		arr[y - 1][x - 1] = cost;
	}

	visit[0] = -1;
	int min;
	int min_indx;

	for (int k = 0; k < N - 1; k++) {
		min = 999999;
		min_indx = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i] == -1) {
				for (int j = 0; j < N; j++) {
					if (visit[j] != -1 && arr[i][j] != 0 && min > arr[i][j]) {
						min = arr[i][j];
						min_indx = j;
					}
				}
			}
		}

		costs += min;
		visit[min_indx] = -1;
	}

	cout << costs << endl;

	return 0;
}