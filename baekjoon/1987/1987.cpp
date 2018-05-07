#include <iostream>
using namespace std;

int R, C;
char arr[21][21] = { 0, };
int alpha[27] = { 0, };
int maxs = 1;

void fn(int x, int y, int mxs);

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	alpha[arr[0][0] - 'A'] = 1;
	int x = 0, y = 0;

	fn(x, y, maxs);

	cout << maxs << endl;

	return 0;
}

void fn(int x, int y, int mxs) {
	if (mxs > maxs) {
		maxs = mxs;
	}

	if (x > 0) {
		if (alpha[arr[x - 1][y] - 'A'] == 0) {
			alpha[arr[x - 1][y] - 'A'] = 1;
			fn(x - 1, y, mxs + 1);
			alpha[arr[x - 1][y] - 'A'] = 0;
		}
	}

	if (x < R - 1) {
		if (alpha[arr[x + 1][y] - 'A'] == 0) {
			alpha[arr[x + 1][y] - 'A'] = 1;
			fn(x + 1, y, mxs + 1);
			alpha[arr[x + 1][y] - 'A'] = 0;
		}
	}

	if (y > 0) {
		if (alpha[arr[x ][y - 1] - 'A'] == 0) {
			alpha[arr[x][y - 1] - 'A'] = 1;
			fn(x, y - 1, mxs + 1);
			alpha[arr[x][y - 1] - 'A'] = 0;
		}
	}

	if (y < C - 1) {
		if (alpha[arr[x][y + 1] - 'A'] == 0) {
			alpha[arr[x][y + 1] - 'A'] = 1;
			fn(x, y + 1, mxs + 1);
			alpha[arr[x][y + 1] - 'A'] = 0;
		}
	}
}