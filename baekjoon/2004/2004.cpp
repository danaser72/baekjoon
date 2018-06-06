#include <iostream>
using namespace std;

long long N, M;
long long two = 0, five = 0;
long long num1, num2;

void func(long long num);

int main() {
	scanf("%lld%lld", &N, &M);
	
	func(N);
	two += num1;
	five += num2;

	func(M);
	two -= num1;
	five -= num2;

	func(N - M);
	two -= num1;
	five -= num2;

	printf("%lld\n", two < five ? two : five);

	return 0;
}

void func(long long num) {
	num1 = 0;
	num2 = 0;

	for (long long i = 2; i <= num; i *= 2) {
		num1 += num / i;
	}

	for (long long i = 5; i <= num; i *= 5) {
		num2 += num / i;
	}
}