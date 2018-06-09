#include <iostream>
using namespace std;

int N;
long long cnt = 5;

int main() {
	cin >> N;

	for (int i = 2; i <= N; i++) {
		cnt += i * 3 + 1;
		cnt %= 45678;
	}

	printf("%lld\n", cnt);

	return 0;
}