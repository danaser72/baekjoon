#include <stdio.h>

int N;
int arr[2010];
int DP[2010][2010] = { 0, };

int M;
int S, E;
int check;

int main() {
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	scanf_s("%d", &M);

	for (int k = 0; k < M; k++) {
		check = 1;

		scanf_s("%d%d", &S, &E);
		S--;
		E--;

		for (int i = 0; i < (E - S + 1) / 2; i++) {
			if (DP[S + i][E - i] == 1) {
				check = 1;
				break;
			}
			else if (DP[S + i][E - i] == 2) {
				check = 0;
				break;
			}
			else {
				if (arr[S + i] != arr[E - i]) {
					check = 0;
					break;
				}
			}
		}
		if (check == 1) {
			for (int j = S, k = E; j <= k; j++, k--) {
				if (DP[j][k] != 0)
					break;
				DP[j][k] = 1;
			}
		}
		else {
			for (int j = S, k = E; j >= 0 && k < N; j--, k++) {
				if (DP[j][k] != 0)
					break;
				DP[j][k] = 2;
			}
		}

		printf("%d\n", check);
	}

	return 0;
}