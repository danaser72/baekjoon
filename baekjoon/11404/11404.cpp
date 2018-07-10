#include <iostream>
using namespace std;

#define INF 987654321

int N, M;
int v[102][102];


int main() {
	cin >> N >> M;

	int x, y, val;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			v[i][j] = i == j ? 0 : INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> val;

		v[x][y] = v[x][y] < val ? v[x][y] : val;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v[i][j] == INF)
				cout << "0 ";
			else
				cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}