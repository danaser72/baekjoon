#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int arr[1002] = { 0, };

int main() {
	scanf("%d", &T);
	//cin >> T;

	while (T--) {
		int cnt = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);

			for (int j = 0; j < i; j++) {
				if (arr[i] >= arr[j]) {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}