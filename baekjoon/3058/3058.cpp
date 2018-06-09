#include <iostream>
using namespace std;

int T;
int nat;

int main() {
	cin >> T;
	while (T--) {
		int sum = 0;
		int min = 101;

		for (int i = 0; i < 7; i++) {
			cin >> nat;
			if (nat % 2 == 0) {
				sum += nat;

				if (min > nat)
					min = nat;
			}
		}

		cout << sum << " " << min << endl;
	}

	return 0;
}