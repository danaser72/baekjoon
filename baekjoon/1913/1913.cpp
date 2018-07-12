#include <iostream>
using namespace std;

//ก่0
//กๆ1
//ก้2
//ก็3

int N, M;
int arr[1000][1000] = { 0, };

int MOVE[][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int rot = 0;

int x, y;

int main() {
	cin >> N >> M;

	int val = 1;
	x = N / 2;
	y = N / 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[x][y] = val++;

			x += MOVE[rot][0];
			y += MOVE[rot][1];

			if (!arr[x + MOVE[(rot + 1) % 4][0]][y + MOVE[(rot + 1) % 4][1]]) {
				rot = (rot + 1) % 4;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
			
			if (arr[i][j] == M) {
				x = i + 1;
				y = j + 1;
			}
		}
		printf("\n");
	}

	printf("%d %d\n", x, y);

	return 0;
}