#include <iostream>
using namespace std;

long long N;
long long pos;
long long ans = 0;

int main() {
	scanf("%lld%lld", &N, &pos);
	long long s = 1;
	long long e = N * N;

	while (s <= e) {
		long long m = (s + e) / 2;
		long long cnt = 0;

		for (long long i = 1; i <= N; i++) {
			long long num = m / i;

			if (num > N) {
				num = N;
			}
			cnt += num;
		}

		if (cnt >= pos) {
			ans = m;
			e = m - 1;
		}
		else if (cnt < pos) {
			s = m + 1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}