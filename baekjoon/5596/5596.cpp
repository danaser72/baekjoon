#include <iostream>
using namespace std;

int S = 0, T = 0;

int main() {
	int num;

	for (int i = 0; i < 4; i++) {
		cin >> num;
		S += num;
	}

	for (int i = 0; i < 4; i++) {
		cin >> num;
		T += num;
	}
	cout << (S >= T ? S : T) << endl;

	return 0;
}