#include <iostream>
using namespace std;

int mon, day;

int main() {
	scanf("%d%d", &mon, &day);

	if (mon < 2) {
		printf("Before\n");
	}
	else if (mon == 2) {
		if (day < 18) {
			printf("Before\n");
		}
		else if (day == 18) {
			printf("Special\n");
		}
		else {
			printf("After\n");
		}
	}
	else {
		printf("After\n");
	}

	return 0;
}