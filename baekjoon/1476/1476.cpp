#include <iostream>
using namespace std;

int E, S, M;
int e = 0, s = 0, m = 0;

int main() {
	cin >> E >> S >> M;
	int k = 1;

	for (k = 1; ; k++) {
		if (e + 1 == E && s + 1 == S && m + 1 == M) {
			break;
		}
		e = (e + 1) % 15;
		s = (s + 1) % 28;
		m = (m + 1) % 19;
	}

	cout << k << endl;

	return 0;
}