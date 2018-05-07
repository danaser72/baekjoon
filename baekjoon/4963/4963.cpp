#include <iostream>
using namespace std;

int w, h;
int coun;
int arr[51][51] = { 0, };
void fn(int x, int y, int cnt);

int main() {

	while (1) {
		cin >> h >> w;
		coun = 1;
		
		if (!w && !h)
			break;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (arr[i][j] == 1) {
					arr[i][j] = ++coun;
					fn(i, j, coun);
				}
			}
		}
		cout << coun - 1 << endl;
	}

	return 0;
}

void fn(int x, int y, int cnt) {
	if (x > 0) {
		if (arr[x - 1][y] == 1) {
			arr[x - 1][y] = cnt;
			fn(x - 1, y, cnt);
		}
		if (y > 0) {
			if (arr[x - 1][y - 1] == 1) {
				arr[x - 1][y - 1] = cnt;
				fn(x - 1, y - 1, cnt);
			}
		}
		if (y < h - 1) {
			if (arr[x - 1][y + 1] == 1) {
				arr[x - 1][y + 1] = cnt;
				fn(x - 1, y + 1, cnt);
			}
		}
	}
	if (y > 0) {
		if (arr[x][y - 1] == 1) {
			arr[x][y - 1] = cnt;
			fn(x, y - 1, cnt);
		}
	}
	if (x < w - 1) {
		if (arr[x + 1][y] == 1) {
			arr[x + 1][y] = cnt;
			fn(x + 1, y, cnt);
		}
		if (y > 0) {
			if (arr[x + 1][y - 1] == 1) {
				arr[x + 1][y - 1] = cnt;
				fn(x + 1, y - 1, cnt);
			}
		}
		if (y < h - 1) {
			if (arr[x + 1][y + 1] == 1) {
				arr[x + 1][y + 1] = cnt;
				fn(x + 1, y + 1, cnt);
			}
		}
	}
	if (y < h - 1) {
		if (arr[x][y + 1] == 1) {
			arr[x][y + 1] = cnt;
			fn(x, y + 1, cnt);
		}
	}
}