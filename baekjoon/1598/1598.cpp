#include <iostream>
using namespace std;

int A, B;
int divA, divB, remA, remB;

int ABS(int a) {
	return a < 0 ? -a : a;
}

int main() {
	cin >> A >> B;
	A--, B--;

	divA = A / 4;
	divB = B / 4;

	remA = A % 4;
	remB = B % 4;

	cout << ABS(divA - divB) + ABS(remA - remB) << endl;


	return 0;
}