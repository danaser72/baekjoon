#include <iostream>
using namespace std;

int T;
double price[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };

int main() {
	cin >> T;

	while (T--) {
		int each;
		double sum = 0;
		for (int i = 0; i < 5; i++) {
			cin >> each;

			sum += each * price[i];
		}

		printf("$%.2f\n", sum);
	}
	return 0;
}