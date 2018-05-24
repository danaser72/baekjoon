#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define RIGHT 1 
#define DOWN 2
#define LEFT 3
#define UP 4

//vector<vector<int>> v;
int v[102][102] = { 0, };
int N, K, L;
int cnt = 0;

void func();

int main() {
	//cin >> N;
	scanf("%d", &N);

	//cin >> K;
	scanf("%d", &K);
	int x, y;

	while (K--) {
		//cin >> x >> y;
		scanf("%d%d", &x, &y);
		v[x - 1][y - 1] = 2;
	}
	v[0][0] = 1;

	func();

	//cout << cnt << endl;
	printf("%d\n", cnt);

	return 0;
}

void func() {
	int x = 0, y = 0;
	int PRE = 0;
	int rot = RIGHT;
	int X;
	char C;
	bool chk;
	queue<pair<int, int>> q;

	q.push({ x,y });

	//cin >> L;
	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		//cin >> X >> C;
		scanf("%d %c", &X, &C);

		for (int j = 0; j < X - PRE; j++) {
			cnt++;
			chk = false;
			if (rot == RIGHT) {
				y++;
			}
			else if (rot == DOWN) {
				x++;
			}
			else if (rot == LEFT) {
				y--;
			}
			else if (rot == UP) {
				x--;
			}

			if (x > N - 1 || y > N - 1 || x < 0 || y < 0 || v[x][y] == 1) {
				return;
			}
			else if (v[x][y] == 2) {
				chk = true;
			}
			v[x][y] = 1;
			q.push({ x,y });

			if (!chk) {
				v[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}

		PRE = X;

		if (C == 'L') {
			rot = (rot + 3) % 4;

			if (rot == 0)
				rot = 4;
		}
		else if (C == 'D') {
			rot = rot % 4 + 1;
		}
	}

	while (1) {
		cnt++;
		if (rot == RIGHT) {
			y++;
		}
		else if (rot == DOWN) {
			x++;
		}
		else if (rot == LEFT) {
			y--;
		}
		else if (rot == UP) {
			x--;
		}

		if (x > N - 1 || y > N - 1 || x < 0 || y < 0 || v[x][y] == 1) {
			return;
		}
	}
}