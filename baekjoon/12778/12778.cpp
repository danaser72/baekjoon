#include <iostream>
using namespace std;

int T;
int M;
char ch;

int main() {
	cin >> T;

	while (T--) {
		cin >> M >> ch;

		if (ch == 'C') {
			for (int i = 0; i < M; i++) {
				cin >> ch;
				cout << (int)(ch - 'A' + 1) << " ";
			}
			cout << endl;
		}
		else if (ch == 'N') {
			for (int i = 0; i < M; i++) {
				int t;
				cin >> t;
				cout << (char)(t + 'A' - 1) << " ";
			}
			cout << endl;
		}
	}

	return 0;
}