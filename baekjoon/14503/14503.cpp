#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int arr[51][51] = { 0, };
bool chk;
int cnt = 0;
int drct[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main() {
	//cin >> N >> M;
	//cin >> r >> c >> d;

	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &r, &c, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> arr[i][j];
			scanf("%d", &arr[i][j]);
		}
	}

	chk = false;
	while (1) {
		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			if (arr[r + drct[i][0]][c + drct[i][1]] != 0) {
				chk = true;
			}
			else {
				chk = false;
				break;
			}
		}

		if (chk) {
			int t = (d + 2) % 4;

			if (arr[r + drct[t][0]][c + drct[t][1]] == 1)
				break;

			r += drct[t][0];
			c += drct[t][1];
		}
		else {
			d = (d + 3) % 4;

			if (arr[r + drct[d][0]][c + drct[d][1]] == 0) {
				r += drct[d][0];
				c += drct[d][1];
			}
		}
	}

	//cout << cnt << endl;
	printf("%d\n", cnt);

	return 0;
}