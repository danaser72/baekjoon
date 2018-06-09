#include <iostream>
using namespace std;

int A, B, C, D;

int main() {
	cin >> A >> B >> C >> D;

	cout << (A + D < B + C ? A + D : B + C) << endl;

	return 0;
}