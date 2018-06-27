#include <iostream>
using namespace std;

int N;
int arr[10002];
int visit[10002] = { 0, };
int pos = 0;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < N; i++) {
		if (arr[i - 1] < arr[i]) {
			pos = i;
		}
	}

	if (pos == 0) {
		printf("%d\n", -1);
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			printf("%d ", arr[i]);
			visit[arr[i]] = 1;
		}
		for (int i = arr[pos - 1] + 1; i <= N; i++) {
			if (visit[i] == 0) {
				printf("%d ", i);
				visit[i] = 1;
				break;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0)
				printf("%d ", i);
		}
		printf("\n");
	}
	
	return 0;
}