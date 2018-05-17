#include <iostream>
using namespace std;

#define D 0
#define F 1
#define L 2
#define U 3
#define B 4
#define R 5

int N, M, K;
int r, c;
int map[21][21] = { 0, };
int dice[6] = { 0, };
int MOVE[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int main() {
	//cin >> N >> M >> r >> c >> K;
	scanf("%d%d%d%d%d", &N, &M, &r, &c, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> map[i][j];
			scanf("%d", &map[i][j]);
		}
	}

	int dir;
	int now = D;
	while (K--) {
		//cin >> dir;
		scanf ("%d", &dir);
		dir--;
		int n = r + MOVE[dir][0];
		int m = c + MOVE[dir][1];

		if (n >= N || n < 0 || m >= M || m < 0) {
			continue;
		}
		r = n;
		c = m;

		dir++;

		if (dir == 1) {
			int t = dice[R];
			dice[R] = dice[U];
			dice[U] = dice[L];
			dice[L] = dice[D];
			dice[D] = t;
		}
		else if (dir == 2) {
			int t = dice[L];
			dice[L] = dice[U];
			dice[U] = dice[R];
			dice[R] = dice[D];
			dice[D] = t;
		}
		else if (dir == 3) {
			int t = dice[B];
			dice[B] = dice[U];
			dice[U] = dice[F];
			dice[F] = dice[D];
			dice[D] = t;
		}
		else if (dir == 4) {
			int t = dice[F];
			dice[F] = dice[U];
			dice[U] = dice[B];
			dice[B] = dice[D];
			dice[D] = t;
		}
		if (map[n][m] == 0) {
			map[n][m] = dice[D];
		}
		else {
			dice[D] = map[n][m];
			map[n][m] = 0;
		}

		//cout << dice[U] << endl;
		printf("%d\n", dice[U]);
	}

	return 0;
}