#include <iostream>
using namespace std;

int N;
int DP[2][3] = { 0, };
int DP1[2][3] = { 0, };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> DP[1][j];
			DP1[1][j] = DP[1][j];
		}

		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				DP[0][j] = DP[1][j];
				DP1[0][j] = DP1[1][j];
			}
			continue;
		}

		int t0 = DP[0][0], t1 = DP[0][1], t2 = DP[0][2];
		int m0 = DP1[0][0], m1 = DP1[0][1], m2 = DP1[0][2];

		if (t0 > t1) {
			DP[1][0] += t0;

			if (t0 > t2) {
				if (t1 > t2) {	// t0 t1 t2
					DP[1][1] += t0;
					DP[1][2] += t1;
				}
				else {			// t0 t2 t1
					DP[1][1] += t0;
					DP[1][2] += t2;
				}
			}
			else {				// t2 t0 t1
				DP[1][1] += t2;
				DP[1][2] += t2;
			}
		}
		else {
			DP[1][0] += t1;

			if (t1 > t2) {
				DP[1][1] += t1;
				DP[1][2] += t1;
			}
			else {				// t2 t1 t0
				DP[1][1] += t2;
				DP[1][2] += t2;
			}
		}


		if (m0 > m1) {
			DP1[1][0] += m1;

			if (m0 > m2) {
				if (m1 > m2) {	// m0 m1 m2
					DP1[1][1] += m2;
					DP1[1][2] += m2;
				}
				else {			// m0 m2 m1
					DP1[1][1] += m1;
					DP1[1][2] += m1;
				}
			}
			else {				// m2 m0 m1
				DP1[1][1] += m1;
				DP1[1][2] += m1;
			}
		}
		else {
			DP1[1][0] += m0;

			if (m1 > m2) {
				if (m0 > m2) {	// m1 m0 m2
					DP1[1][1] += m2;
					DP1[1][2] += m2;
				}
				else {			// m1 m2 m0
					DP1[1][1] += m0;
					DP1[1][2] += m2;
				}
			}
			else {				// m2 m1 m0
				DP1[1][1] += m0;
				DP1[1][2] += m1;
			}
		}


		for (int j = 0; j < 3; j++) {
			DP[0][j] = DP[1][j];
			DP1[0][j] = DP1[1][j];
		}
	}

	int maxs = 0;
	int mins = 1000000;

	maxs = DP[1][0] > DP[1][1] ? DP[1][0] : DP[1][1];
	maxs = maxs > DP[1][2] ? maxs : DP[1][2];

	mins = DP1[1][0] < DP1[1][1] ? DP1[1][0] : DP1[1][1];
	mins = mins < DP1[1][2] ? mins : DP1[1][2];

	cout << maxs << " " << mins << endl;

	return 0;
}