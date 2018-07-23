#include <iostream>
using namespace std;

// Do not remain
// NAM >= YUNG + 2
// All >= 1
// TAEK : Even

int N;
int NAM, YUNG, TAEK;

int cnt = 0;

int main() {
	cin >> N;

	for (int i = 2; i <= N; i+=2) {
		int t = N;
		t -= i;

		for (int j = 1; 2 * j + 2 <= t; j++) {
			cnt++;
		}
	}

	cout << cnt << endl;


	return 0;
}