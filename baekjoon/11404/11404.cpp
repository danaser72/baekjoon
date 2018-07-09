#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
int v[102][102];

int main() {
	cin >> N >> M;

	int x, y, val;
	memset(v, 0, sizeof(v));

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> val;

		v[x][y] = val;
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}