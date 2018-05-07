#include <iostream>
using namespace  std;

int N;
int arr[15][15] = { 0, };
int ys[15] = { 0, };
void fn(int x);

long mxs = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr[0][i] = 1;
		ys[i] = 1;
		fn(1);
		arr[0][i] = 0;
		ys[i] = 0;
	}

	cout << mxs << endl;

	return 0;
}

void fn(int x) {
	if (x == N) {
		mxs++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (ys[i] == 0) {
			int check = 1;
			for (int j = x; j > 0; j--) {
				if (i + j < N) {
					if (arr[x - j][i + j] == 1) {
						check = 0;
						break;
					}
				}
				if (i - j >= 0) {
					if (arr[x - j][i - j] == 1) {
						check = 0;
						break;
					}
				}
			}
			if (check) {
				arr[x][i] = 1;
				ys[i] = 1;
				fn(x + 1);
				arr[x][i] = 0;
				ys[i] = 0;
			}
		}
	}
}