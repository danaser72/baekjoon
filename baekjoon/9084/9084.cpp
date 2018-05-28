/*
** reference : http://wootool.tistory.com/177
*/

#include <iostream>
using namespace std;

#define MAX 10000

int T;
int N, M;
int coin[22];


int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> coin[i];

		cin >> M;

		int DP[MAX + 2] = { 1, };

		for (int i = 0; i < N; i++) {
			DP[coin[i]]++;
			for (int j = coin[i] + 1; j <= M; j++) {
				DP[j] = DP[j] + DP[j - coin[i]];
			}
		}

		cout << DP[M] << endl;
	}

	return 0;
}