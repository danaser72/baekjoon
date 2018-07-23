#include <iostream>
using namespace std;

long long sum;
long long t;

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> t;

		sum += t;
	}

	cout << sum << endl;

	return 0;
}