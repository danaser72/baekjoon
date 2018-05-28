#include <iostream>
#include <string.h>
using namespace std;

int M, x;
int arr[22] = { 0, };
char commend[8];

int main() {
	scanf("%d", &M);

	while (M--) {
		scanf(" %s%d", &commend, &x);

		if (!strcmp("add", commend)) {
			arr[x] = 1;
		}
		else if (!strcmp("remove", commend)) {
			arr[x] = 0;
		}
		else if (!strcmp("check", commend)) {
			printf("%d\n", arr[x]);
		}
		else if (!strcmp("toggle", commend)) {
			arr[x] = !arr[x];
		}
		else if (!strcmp("all", commend)) {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (!strcmp("empty", commend)) {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}

	return 0;
}