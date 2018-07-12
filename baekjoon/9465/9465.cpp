#include <iostream>
#include <string.h>
using namespace std;

int T, N;
int arr[100002][2];
int score[100002][2];
int MAX;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		MAX = 0;
		memset(score, -1, sizeof(score));

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[j][i]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				score[i][j] = arr[i][j];
			}
			for (int j = 0; j < i; j++) {
				if (j == i - 1) {
					int k = 1;
					if (score[i][0] < score[j][k] + arr[i][0]) {
						score[i][0] = score[j][k] + arr[i][0];

						if (MAX < score[i][0])
							MAX = score[i][0];
					}
					k = 0;
					if (score[i][1] < score[j][k] + arr[i][1]) {
						score[i][1] = score[j][k] + arr[i][1];

						if (MAX < score[i][1])
							MAX = score[i][1];
					}
				}
				else {
					for (int k = 0; k < 2; k++) {
						if (score[i][0] < score[j][k] + arr[i][0]) {
							score[i][0] = score[j][k] + arr[i][0];

							if (MAX < score[i][0])
								MAX = score[i][0];
						}

						if (score[i][1] < score[j][k] + arr[i][1]) {
							score[i][1] = score[j][k] + arr[i][1];

							if (MAX < score[i][1])
								MAX = score[i][1];
						}
					}
				}
			}
		}

		cout << MAX << endl;
	}

	return 0;
}