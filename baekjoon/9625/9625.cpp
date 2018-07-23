#include <iostream>
using namespace std;

int N;
int A = 1, B = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a = A, b = B;

		A = b;
		B = a + b;
	}

	cout << A << " " << B << endl;

	return 0;
}