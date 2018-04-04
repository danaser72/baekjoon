#include <iostream>
using namespace std;

int T, N;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		int cnt = 0;
		int arr[1003][2] = { 0, };

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i][0]);
		}

		for (int i = 1; i <= N; i++) {
			if (arr[i][1] == 0) {
				cnt++;

				arr[i][1] = 1;
				int j = arr[i][0];

				while (!arr[j][1]) {
					arr[j][1] = 1;
					j = arr[j][0];
				}
			}
		}

		printf("%d\n", cnt);
	}


	return 0;
}