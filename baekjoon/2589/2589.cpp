#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
char arr[55][55];
int v[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };

int row, col, MAX = 0;

void func();

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L')
				q.push({ i,j });
		}
	}

	func();
	if (MAX == 0)
		cout << "0" << endl;
	else
		cout << MAX - 1 << endl;

	return 0;
}

void func() {
	while (!q.empty()) {
		int arr_int[55][55] = { 0, };
		queue<pair<int, pair<int, int>>> bfs;
		int R = q.front().first, C = q.front().second;
		bfs.push({ 1, { R,C } });
		arr_int[R][C] = 1;

		while (!bfs.empty()) {
			for (int i = 0; i < 4; i++) {
				int R1 = bfs.front().second.first + v[i][0];
				int C1 = bfs.front().second.second + v[i][1];
				int val1 = bfs.front().first + 1;

				if ((R1 >= 0 && C1 >= 0 || R1 < row - 1 && C1 < col - 1) && arr_int[R1][C1] == 0 && arr[R1][C1] == 'L') {
					bfs.push({ val1, {R1, C1} });
					arr_int[R1][C1] = val1;
					if (MAX < val1)
						MAX = val1;
				}
			}

			bfs.pop();
		}

		q.pop();
	}
}