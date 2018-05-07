#include <iostream>
using namespace std;

int N;
long long val = 0;
long long rem = 1;
long long square(long long K);

int main() {
	cin >> N;

	for (int i = 0; i < 9; i++) {
		rem *= 10;
	}
	rem += 7;

	for (int k = 0; k < N; k++) {
		long long a, b, bt;
		cin >> a >> b;
		bt = b% rem;
		val = val + (a * square(b - 1) * bt) % rem;
		val %= rem;
	}

	cout << val << endl;

	return 0;
}

long long square(long long K) {
	long long a = 1;
	for (long long i = 0; i < K; i++){
		a *= 2;
		a %= rem;
	}

	return a;
}