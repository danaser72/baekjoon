#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

int R, C;
int MOVE[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char map[50][50] = { 0, };
void func(queue<pair<int, pair<int, int>>>, queue<pair<int, int>>);
int MIN = INF;


int main() {
	queue<pair<int, pair<int, int>>> S;
	queue<pair<int, int>> water;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S') {
				S.push({0, { i,j } });
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}

	func(S, water);

	if (MIN == INF)
		cout << "KAKTUS" << endl;
	else
		cout << MIN << endl;

	return 0;
}

void func(queue<pair<int, pair<int, int>>> S, queue<pair<int, int>> W) {
	bool isMove = true;

	while (isMove) {
		isMove = false;
		queue<pair<int, int>> t_w = W;

		while (!t_w.empty()) {
			int m = t_w.front().first;
			int n = t_w.front().second;
			t_w.pop();
			W.pop();

			for (int i = 0; i < 4; i++) {
				int x = m + MOVE[i][0];
				int y = n + MOVE[i][1];

				if ((x >= 0 && x < R) && (y >= 0 && y < C)) {
					if (map[x][y] == '*' || map[x][y] == 'D')
						continue;
					if (map[x][y] != 'X') {
						map[x][y] = '*';
						W.push({ x,y });
					}
				}
			}
		}

		queue<pair<int, pair<int, int>>> t_s = S;
		while (!t_s.empty()) {
			int m = t_s.front().second.first;
			int n = t_s.front().second.second;
			int val = t_s.front().first + 1;
			t_s.pop();
			S.pop();

			for (int i = 0; i < 4; i++) {
				int x = m + MOVE[i][0];
				int y = n + MOVE[i][1];

				if ((x >= 0 && x < R) && (y >= 0 && y < C)) {
					if (map[x][y] == 'D') {
						MIN = val < MIN ? val : MIN;
					}
					if (map[x][y] == 'S')
						continue;
					if (map[x][y] != 'X' && map[x][y] != '*') {
						isMove = true;
						map[x][y] = 'S';
						S.push({val, { x,y } });
					}
				}
			}
		}
	}
}