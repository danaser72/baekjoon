#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[502][502] = { 0, };
int shape[19][4][2] = {
	{ { 0,0 },{ 0,1 },{ 0,2 },{ 0,3 } },
	{ { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } },

	{ { 0,0 },{ 1,0 },{ 0,1 },{ 1,1 } },

	{ { 0,0 },{ 1,0 },{ 1,1 },{ 2,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 },{ 1,2 } },
	{ { 1,0 },{ 1,1 },{ 0,1 },{ 0,2 } },
	{ { 0,1 },{ 1,1 },{ 1,0 },{ 2,0 } },

	{ { 0,1 },{ 1,0 },{ 1,1 },{ 1,2 } },
	{ { 0,0 },{ 0,1 },{ 0,2 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 },{ 2,0 } },
	{ { 1,0 },{ 0,1 },{ 1,1 },{ 2,1 } },

	{ { 0,0 },{ 1,0 },{ 2,0 },{ 2,1 } },
	{ { 0,1 },{ 1,1 },{ 2,0 },{ 2,1 } },
	{ { 0,0 },{ 1,0 },{ 0,1 },{ 0,2 } },
	{ { 0,0 },{ 1,2 },{ 0,1 },{ 0,2 } },

	{ { 0,0 },{ 0,1 },{ 1,1 },{ 2,1 } },
	{ { 0,0 },{ 0,1 },{ 1,0 },{ 2,0 } },
	{ { 1,0 },{ 1,1 },{ 1,2 },{ 0,2 } },
	{ { 0,0 },{ 1,0 },{ 1,1 },{ 1,2 } }
};

int MAX = 0;

void search(int, int);

int main() {
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cin >> arr[i][j];
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			search(i, j);
		}
	}

	//cout << MAX << endl;
	printf("%d\n", MAX);

	return 0;
}

void search(int x, int y) {
	int m, n;
	int val;
	bool chk;

	for (int i = 0; i < 19; i++) {
		val = 0;
		chk = true;
		for (int j = 0; j < 4; j++) {
			n = x + shape[i][j][0];
			m = y + shape[i][j][1];

			if (n >= N || m >= M) {
				chk = false;
				break;
			}
			val += arr[n][m];
		}

		if (chk) {
			if (val > MAX)
				MAX = val;
		}
	}
}