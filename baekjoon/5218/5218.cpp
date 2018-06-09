#include <iostream>
#include <string.h>
using namespace std;

int T;
char x[22], y[22];

int main() {
	cin >> T;

	while (T--) {
		scanf(" %s %s", &x, &y);

		int len = strlen(x);

		cout << "Distances: ";
		for (int i = 0; i < len; i++) {
			if (x[i] <= y[i]) {
				printf("%d ", y[i] - x[i]);
			}
			else {
				printf("%d ", y[i] + 26 - x[i]);
			}
		}
		printf("\n");
	}
	return 0;
}