#include <iostream>
using namespace std;

long long A, B;
long long sum;

int main() {
	scanf("%lld%lld", &A, &B);

	if (A > B) {
		long long t = A;
		A = B;
		B = t;
	}
	long long N = B - A + 1;

	printf("%lld\n", (A + B) * N / 2);

	return 0;
}