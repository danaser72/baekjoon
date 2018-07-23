#include <iostream>
using namespace std;

int N;

int main() {
	while (1) {
		int sum = 0;
		cin >> N;

		if (N == 0)
			break;

		for (int i = 1; i <= N; i++) {
			int t = 0;
			for (int j = 0; j + i <= N; j++) {
				t++;
			}
			sum += t * t;
		}
		cout << sum << endl;
	}
	return 0;
}