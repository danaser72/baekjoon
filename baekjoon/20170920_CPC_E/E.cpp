#include <iostream>
using namespace std;

int N;
long long val = 0;

int main() {
	cin >> N;

	for (int k = 0; k < N; k++) {
		int a, b;

		cin >> a >> b;

		val += a*b;
	}

	cout << val << endl;

	return 0;
}