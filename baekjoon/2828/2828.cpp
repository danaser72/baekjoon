#include <iostream>
using namespace std;

int N, M, J;

int main() {
	cin >> N >> M >> J;

	int s = 1, e = M;

	int MOVE = 0;
	int pos;
	for (int i = 0; i < J; i++) {
		cin >> pos;

		while (1) {
			if (s <= pos && e >= pos) {
				break;
			}
			else if (e < pos) {
				s++; e++;
				MOVE++;
			}
			else if (s > pos) {
				s--; e--;
				MOVE++;
			}
		}
	}

	cout << MOVE << endl;

	return 0;
}