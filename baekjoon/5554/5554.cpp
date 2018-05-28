#include <iostream>
using namespace std;

int t, val = 0;

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> t;
		val += t;
	}
	cout << val / 60 << endl << val % 60 << endl;

	return 0;
}