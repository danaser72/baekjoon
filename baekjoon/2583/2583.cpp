#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[101][101] = { 0, };

int x, y, x2, y2;
int area;
int areas[10102] = { 0, };

void fn(int x, int y, int area);

int main() {
	cin >> N >> M >> K;

	for (int k = 0; k < K; k++) {
		cin >> x >> y >> x2 >> y2;

		for (int i = x; i < x2; i++) {
			for (int j = y; j < y2; j++) {
				arr[i][j] = -1;
			}
		}
	}

	area = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				area++;
				arr[i][j] = area;
				areas[area - 1] ++;
				fn(i, j, area);
			}
		}
	}

	sort(areas, areas + area);
	cout << area << endl;

	for (int i = 0; i < area; i++) {
		cout << areas[i] << " ";
	}
	cout << endl;

	return 0;
}

void fn(int x, int y, int area) {
	if (x > 0) {
		if (arr[x - 1][y] == 0) {
			arr[x - 1][y] = area;
			areas[area - 1] ++;
			fn(x - 1, y, area);
		}
	}

	if (x < M - 1) {
		if (arr[x + 1][y] == 0) {
			arr[x + 1][y] = area;
			areas[area - 1] ++;
			fn(x + 1, y, area);
		}
	}

	if (y > 0) {
		if (arr[x][y - 1] == 0) {
			arr[x][y - 1] = area;
			areas[area - 1] ++;
			fn(x, y - 1, area);
		}
	}

	if (y < N - 1) {
		if (arr[x][y + 1] == 0) {
			arr[x][y + 1] = area;
			areas[area - 1] ++;
			fn(x, y + 1, area);
		}
	}
}