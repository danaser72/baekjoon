#include <iostream>
using namespace std;

int T;
int N, M;

int main() {
	cin >> T;
	
	while (T--) {
		int map[102][102];
		int one[102] = { 0, };
		int cnt = 0;

		scanf("%d%d", &N, &M);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)
					one[j]++;
			}
		}

		for (int j = 0; j < M; j++) {
			int pos = 0;
			for (int i = N - 1; i >= 0 && one[j]; i--) {
				if (map[i][j] == 1) {
					cnt += pos * one[j];
					one[j] --;
					pos = 0;
				}
				else {
					pos++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}