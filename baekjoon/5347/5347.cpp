#include <iostream>
using namespace std;

int T;
int a, b;

int main() {
	cin >> T;

	while (T--) {
		cin >> a >> b;
		int m = a, n = b;

		while (m != n) {
			if (m > n) {
				n += b;
			}
			else if (m < n) {
				m += a;
			}
		}

		cout << m << endl;
	}

	return 0;
}