#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
	cin >> T;
	getchar();

	while (T--) {
		int i = 0;
		char t;

		while (1) {
			char c[52];
			t = getchar();

			if (t == '\n')
				break;

			c[i++] = t;

			if (i != 0) {
				if (c[i - 2] == '(' && c[i - 1] == ')') {
					i -= 2;
				}
			}
		}

		if (i == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}