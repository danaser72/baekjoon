#include <iostream>
#include <math.h>
using namespace std;

int N;
long long C, K;

int main() {
	cin >> N;

	long long rem = 0;
	long long val = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;

	for (int i = 0; i < N; i++) {
		//cin >> C >> K;
		scanf("%lli%lli", &C, &K);
		long long a = 1;

		for (int i = 0; i < K - 1; i++) {
			a *= 2;
			if (a >= val) {
				a %= val;
			}
		}
		C = ((C % val) * (K % val)) % val;
		a = ((a % val) * (C % val)) % val;
		rem = (rem + a) % val;
	}

	cout << rem << endl;

	return 0;
}