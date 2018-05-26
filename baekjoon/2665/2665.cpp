#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
	int x;
	int y;
	int cnt;
};

int MOVE[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int N;

void func(queue<node> q);
vector<vector<char>> v;


int cache[52][52] = { 0, };

int main() {
	scanf("%d", &N);

	node newNode;

	for (int i = 0; i < N; i++) {
		vector<char> element;
		for (int j = 0; j < N; j++) {
			char t;
			scanf(" %c", &t);

			element.push_back(t);
			cache[i][j] = 987654321;
		}
		v.push_back(element);
	}

	newNode.x = 0;
	newNode.y = 0;
	newNode.cnt = 0;

	queue<node> q;
	q.push(newNode);

	func(q);

	//cout << cache[N - 1][N - 1] << endl;
	printf("%d\n", cache[N - 1][N - 1]);

	return 0;
}

void func(queue<node> q) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;

		q.pop();

		if (cnt < cache[x][y]) {
			cache[x][y] = cnt;

			for (int i = 0; i < 4; i++) {
				int n = x + MOVE[i][0], m = y + MOVE[i][1];

				if (n >= 0 && n < N && m >= 0 && m < N) {
					node newNode;
					newNode.x = n;
					newNode.y = m;
					newNode.cnt = cnt;
					if (v[n][m] == '0') {
						newNode.cnt++;
					}

					q.push(newNode);
				}
			}
		}
	}
}