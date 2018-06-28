#include <iostream>
using namespace std;

int fibo[31] = { 1, 1, };
long long D, K;
long long A = 1, B;

int main() {
	cin >> D >> K;

	for (int i = 2; i < D; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	while (1) {
		if ((K - A * fibo[D - 3]) % fibo[D - 2] == 0) {
			B = (K - A * fibo[D - 3]) / fibo[D - 2];
			break;
		}
		else {
			A++;
		}
	}

	if (A > B) {
		long long t = A;
		A = B;
		B = t;
	}

	cout << A << endl << B << endl;

	return 0;
}