#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct Double {
	long long nat;
	long long real;
	int size;
};

int N;
string T;
Double t;
Double range[2];
long long fri[50000][2];
int ans = 1;

int main() {
	t.nat = 0;
	t.real = 0;
	t.size = 0;
	cin >> N >> T;

	size_t pos = T.find('.');
	if (pos != string::npos) {
		int val = 1;
		for (int i = pos - 1; i >= 0; i--) {
			t.nat += val * (T[i] - '0');
			val *= 10;
		}
		val = 1;

		for (int i = T.size() - 1; i > pos; i--) {
			t.real += val * (T[i] - '0');
			val *= 10;
			t.size = val;
		}
	}
	else {
		int val = 1;
		for (int i = T.size() - 1; i >= 0; i--) {
			t.nat += val * (T[i] - '0');
			val *= 10;
		}
		t.real = 0;
		t.size = 1;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &fri[j][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		long long up = 0;
		if (i == 0) {
			up = (t.real * fri[i][1]) / t.size;

			// +
			if (fri[i][0] > fri[i][1] * t.nat + up) {
				range[0].nat = fri[i][0] - (fri[i][1] * t.nat + up) - 1;
				range[0].real = t.size - (fri[i][1] * t.real) % t.size;
			}
			// -
			else {
				range[0].nat = fri[i][0] - fri[i][1] * t.nat + up;
				range[0].real = (fri[i][1] * t.real) % t.size;
			}

			range[1].nat = fri[i][1] * t.nat + up + fri[i][0];
			range[1].real = (fri[i][1] * t.real) % t.size;
		}
		else {
			Double num[2];
			up = (t.real * fri[i][1]) / t.size;

			// +
			if (fri[i][0] > fri[i][1] * t.nat + up) {
				num[0].nat = fri[i][0] - (fri[i][1] * t.nat + up) - 1;
				num[0].real = t.size - (fri[i][1] * t.real) % t.size;
			}
			// -
			else {
				num[0].nat = fri[i][0] - fri[i][1] * t.nat + up;
				num[0].real = (fri[i][1] * t.real) % t.size;
			}

			num[1].nat = fri[i][1] * t.nat + up + fri[i][0];
			num[1].real = (fri[i][1] * t.real) % t.size;

			if ((num[1].nat < range[0].nat || (num[1].nat == range[0].nat && num[1].real < range[0].real))
				|| num[0].nat > range[1].nat || (num[0].nat == range[1].nat && num[0].real > range[1].real)) {
				ans = 0;
				break;
			}
			else {
				if (num[0].nat > range[0].nat || (num[0].nat == range[0].nat && num[0].real >= range[0].real)) {
					range[0].nat = num[0].nat;
					range[0].real = num[0].real;
				}

				if (num[1].nat < range[1].nat || (num[1].nat == range[1].nat && num[1].real <= range[1].real)) {
					range[1].nat = num[1].nat;
					range[1].real = num[1].real;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}