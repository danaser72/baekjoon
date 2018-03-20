#include <stdio.h>

int main() {
	int n;
	int val;

	scanf("%d", &n);

	while (1) {
		scanf("%d", &val);
		if (val == 0) {
			return 0;
		}
		printf("%d is ", val);
		if (val % n != 0)
			printf("NOT ");

		printf("a multiple of %d.\n", n);
	}
}