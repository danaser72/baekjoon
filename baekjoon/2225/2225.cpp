#include <iostream>
using namespace std;

int N, K;
long long DP[202][202] = { 0, };
long long rem = 1000000000;

long long func(long long val, int pos);

int main() {
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		DP[i][1] = 1;
		DP[i][2] = i + 1;
	}

	func(N, K);

	cout << DP[N][K] % rem << endl;

	return 0;
}

long long func(long long val, int pos) {
	if (DP[val][pos] != 0)
		return DP[val][pos];

	for (long long i = 0; i <= val; i++) {
		int t = pos - 1;
		if (t < 1)
			t = 1;
		DP[val][pos] = (DP[val][pos] + func(val - i, t)) % rem;
	}

	return DP[val][pos];
}