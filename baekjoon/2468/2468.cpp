#include <iostream>
using namespace std;

int N;
int arr[101][101] = { 0, };
int temp[101][101] = { 0, };
int maxs = 0;
int mins = 101;
int area;
int max_area = 1;

void fn(int x, int y, int mxs);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (maxs < arr[i][j])
				maxs = arr[i][j];
			if (mins > arr[i][j])
				mins = arr[i][j];
		}
	}

	for (int k = mins; k < maxs; k++) {
		area = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] <= k)
					temp[i][j] = -1;
				else
					temp[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] == 0) {
					area++;
					fn(i, j, area);
				}
			}
		}

		if (max_area < area) {
			max_area = area;
		}
	}

	cout << max_area << endl;

	return 0;
}

void fn(int x, int y, int mxs) {
	if (x > 0) {
		if (temp[x - 1][y] == 0) {
			temp[x - 1][y] = mxs;
			fn(x - 1, y, mxs);
		}
	}
	
	if (x < N - 1) {
		if (temp[x + 1][y] == 0) {
			temp[x + 1][y] = mxs;
			fn(x + 1, y, mxs);
		}
	}

	if (y > 0) {
		if (temp[x][y - 1] == 0) {
			temp[x][y - 1] = mxs;
			fn(x, y - 1, mxs);
		}
	}

	if (y < N - 1) {
		if (temp[x][y + 1] == 0) {
			temp[x][y + 1] = mxs;
			fn(x, y + 1, mxs);
		}
	}
}