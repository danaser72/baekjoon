#include <iostream>
#include <queue>
using namespace std;

/*
#define L 1
#define R 2
#define U 3
#define D 4
*/

struct node {
	pair<int, int> red;
	pair<int, int> blue;
	int cnt;
};

int N, M;
pair<int, int> goal;
char board[13][13];

void func(queue<node> q);

int main() {
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	pair<int, int> red;
	pair<int, int> blue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> board[i][j];
			scanf(" %c", &board[i][j], 1);

			if (board[i][j] == 'B')
				blue = { i,j };
			else if (board[i][j] == 'R')
				red = { i,j };
			else if (board[i][j] == 'O')
				goal = { i,j };
		}
	}

	queue<node> q;
	node newNode;
	newNode.red = red;
	newNode.blue = blue;
	newNode.cnt = 0;

	q.push(newNode);

	func(q);

	return 0;
}

void func(queue<node> q) {
	int val = -1;
	bool chk1 = false;
	bool chk2 = false;

	while (!q.empty()) {
		pair<int, int> red = q.front().red;
		pair<int, int> blue = q.front().blue;
		int cnt = q.front().cnt + 1;
		q.pop();

		int rx, ry;
		int bx, by;
		node newNode;

		if (cnt > 10) {
			break;
		}

		//1
		chk1 = false;
		chk2 = false;
		rx = red.first, ry = red.second;
		bx = blue.first, by = blue.second;

		for (ry; ry > 0; ry--) {
			if (rx == goal.first && ry == goal.second) {
				chk1 = true;
				break;
			}
			if (board[rx][ry - 1] == '#') {
				break;
			}
		}

		for (by; by > 0; by--) {
			if (bx == goal.first && by == goal.second) {
				chk2 = true;
				break;
			}
			if (board[bx][by - 1] == '#') {
				break;
			}
		}

		if (chk1 != chk2 && chk1) {
			val = cnt;
			break;
		}
		else if (chk1 == chk2 && !chk1) {
			if (rx == bx && ry == by) {
				if (red.second > blue.second) {
					ry++;
				}
				else if (red.second < blue.second) {
					by++;
				}
			}
			newNode.red = { rx, ry };
			newNode.blue = { bx, by };
			newNode.cnt = cnt;
			q.push(newNode);
		}

		// 2
		chk1 = false;
		chk2 = false;
		rx = red.first, ry = red.second;
		bx = blue.first, by = blue.second;

		for (ry; ry < M - 1; ry++) {
			if (rx == goal.first && ry == goal.second) {
				chk1 = true;
				break;
			}
			if (board[rx][ry + 1] == '#') {
				break;
			}
		}

		for (by; by < M - 1; by++) {
			if (bx == goal.first && by == goal.second) {
				chk2 = true;
				break;
			}
			if (board[bx][by + 1] == '#') {
				break;
			}
		}
		
		if (chk1 != chk2 && chk1) {
			val = cnt;
			break;
		}
		else if (chk1 == chk2 && !chk1) {
			if (rx == bx && ry == by) {
				if (red.second > blue.second) {
					by--;
				}
				else if (red.second < blue.second) {
					ry--;
				}
			}
			newNode.red = { rx, ry };
			newNode.blue = { bx, by };
			newNode.cnt = cnt;
			q.push(newNode);
		}

		// 3
		chk1 = false;
		chk2 = false;
		rx = red.first, ry = red.second;
		bx = blue.first, by = blue.second;

		for (rx; rx > 0; rx--) {
			if (rx == goal.first && ry == goal.second) {
				chk1 = true;
				break;
			}
			if (board[rx - 1][ry] == '#') {
				break;
			}
		}

		for (bx; bx > 0; bx--) {
			if (bx == goal.first && by == goal.second) {
				chk2 = true;
				break;
			}
			if (board[bx - 1][by] == '#') {
				break;
			}
		}

		if (chk1 != chk2 && chk1) {
			val = cnt;
			break;
		}
		else if (chk1 == chk2 && !chk1){
			if (rx == bx && ry == by) {
				if (red.first > blue.first) {
					rx++;
				}
				else if (red.first < blue.first) {
					bx++;
				}
			}
			newNode.red = { rx, ry };
			newNode.blue = { bx, by };
			newNode.cnt = cnt;
			q.push(newNode);
		}

		// 4
		chk1 = false;
		chk2 = false;
		rx = red.first, ry = red.second;
		bx = blue.first, by = blue.second;

		for (rx; rx < N - 1; rx++) {
			if (rx == goal.first && ry == goal.second) {
				chk1 = true;
				break;
			}
			if (board[rx + 1][ry] == '#') {
				break;
			}
		}

		for (bx; bx < N - 1; bx++) {
			if (bx == goal.first && by == goal.second) {
				chk2 = true;
				break;
			}
			if (board[bx + 1][by] == '#') {
				break;
			}
		}
		
		if (chk1 != chk2 && chk1) {
			val = cnt;
			break;
		}
		else if (chk1 == chk2 && !chk1) {
			if (rx == bx && ry == by) {
				if (red.first > blue.first) {
					bx--;
				}
				else if (red.first < blue.first) {
					rx--;
				}
			}
			newNode.red = { rx, ry };
			newNode.blue = { bx, by };
			newNode.cnt = cnt;
			q.push(newNode);
		}
	}

	//cout << val << endl;
	printf("%d\n", val);
}