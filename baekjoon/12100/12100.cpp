#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define L 1
#define R 2
#define U 3
#define D 4

struct node {
	vector<vector<int>> board;
	int cnt;
};

int N;
int MIN = 0;
void func(queue<node> q);

int main() {
	vector<vector<int>> b;
	//cin >> N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		vector<int> element;
		for (int j = 0; j < N; j++) {
			int t;
			//cin >> t;
			scanf("%d", &t);

			element.push_back(t);
		}
		b.push_back(element);
	}

	node newNode;
	newNode.board = b;
	newNode.cnt = 0;

	queue<node> q;
	q.push(newNode);

	func(q);

	//cout << MIN << endl;
	printf("%d\n", MIN);

	return 0;
}

void func(queue<node> q) {
	while (!q.empty()) {
		vector<vector<int>> board = q.front().board;
		vector<vector<int>> b;
		node newNode;
		int cnt = q.front().cnt;

		q.pop();

		if (cnt >= 5)
			break;

		//1
		b = board;

		for (int i = 0; i < N; i++) {
			int t = 0;
			int x = -1;
			bool chk = false;
			for (int j = 0; j < N; j++) {
				if (b[i][j] != 0) {
					if (x == -1) {
						x = j;
					}
					else {
						if (b[i][x] == b[i][j]) {
							b[i][x] = b[i][x] * 2;
							b[i][j] = 0;
							t++;
							x = -1;
							chk = true;
						}
						else {
							x = j;
						}
					}
				}
			}

			for (int j = 0; j < N && (N - t); j++) {
				if (b[i][j] == 0) {
					for (int k = j + 1; k < N; k++) {
						if (b[i][k] != 0) {
							b[i][j] = b[i][k];
							b[i][k] = 0;
							t++;
							break;
						}
					}
				}
				MIN = b[i][j] > MIN ? b[i][j] : MIN;
			}
		}

		newNode.board = b;
		newNode.cnt = cnt + 1;
		q.push(newNode);

		//2
		b = board;

		for (int i = 0; i < N; i++) {
			int t = 0;
			int x = -1;
			bool chk = false;
			for (int j = N - 1; j >= 0; j--) {
				if (b[i][j] != 0) {
					if (x == -1) {
						x = j;
					}
					else {
						if (b[i][x] == b[i][j]) {
							b[i][x] = b[i][x] * 2;
							b[i][j] = 0;
							t++;
							x = -1;
							chk = true;
						}
						else {
							x = j;
						}
					}
				}
			}

			for (int j = N - 1; j >= 0 && (N - t); j--) {
				if (b[i][j] == 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (b[i][k] != 0) {
							b[i][j] = b[i][k];
							b[i][k] = 0;
							t++;
							break;
						}
					}
				}
				MIN = b[i][j] > MIN ? b[i][j] : MIN;
			}
		}
		
		newNode.board = b;
		newNode.cnt = cnt + 1;
		q.push(newNode);

		//3
		b = board;

		for (int i = 0; i < N; i++) {
			int t = 0;
			int x = -1;
			bool chk = false;
			for (int j = 0; j < N; j++) {
				if (b[j][i] != 0) {
					if (x == -1) {
						x = j;
					}
					else {
						if (b[x][i] == b[j][i]) {
							b[x][i] = b[x][i] * 2;
							b[j][i] = 0;
							t++;
							x = -1;
							chk = true;
						}
						else {
							x = j;
						}
					}
				}
			}

			for (int j = 0; j < N && (N - t); j++) {
				if (b[j][i] == 0) {
					for (int k = j + 1; k < N; k++) {
						if (b[k][i] != 0) {
							b[j][i] = b[k][i];
							b[k][i] = 0;
							t++;
							break;
						}
					}
				}
				MIN = b[j][i] > MIN ? b[j][i] : MIN;
			}
		}
		
		newNode.board = b;
		newNode.cnt = cnt + 1;
		q.push(newNode);

		//4
		b = board;

		for (int i = 0; i < N; i++) {
			int t = 0;
			int x = -1;
			bool chk = false;
			for (int j = N - 1; j >= 0; j--) {
				if (b[j][i] != 0) {
					if (x == -1) {
						x = j;
					}
					else {
						if (b[x][i] == b[j][i]) {
							b[x][i] = b[x][i] * 2;
							b[j][i] = 0;
							t++;
							x = -1;
							chk = true;
						}
						else {
							x = j;
						}
					}
				}
			}

			for (int j = N - 1; j >= 0 && (N - t); j--) {
				if (b[j][i] == 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (b[k][i] != 0) {
							b[j][i] = b[k][i];
							b[k][i] = 0;
							t++;
							break;
						}
					}
				}
				MIN = b[j][i] > MIN ? b[j][i] : MIN;
			}
		}

		newNode.board = b;
		newNode.cnt = cnt + 1;
		q.push(newNode);
	}
}