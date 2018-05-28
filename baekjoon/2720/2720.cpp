#include <iostream>
using namespace std;

int T;
int price;
int coin[4] = { 25, 10, 5, 1 };

int main() {
	cin >> T;

	while (T--) {
		cin >> price;

		for (int i = 0; i < 4; i++) {
			cout << price / coin[i] << " ";
			price %= coin[i];
		}
		cout << endl;
	}
	return 0;
}