#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int arr[101][101][101] = { 0, };
int days = 1;
queue<int> q;

int main() {
	bool c = true;
	cin >> N >> M >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 0) {
					days = 0;
				}
			}
		}
	}


	cout << days - 1 << endl;

	return 0;
}