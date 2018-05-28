#include <iostream>
using namespace std;

int gcd(int a, int rem) {
	if (a % rem == 0) {
		return rem;
	}
	return gcd(rem, a % rem);
}

int N;
int fir, rot;
int x = 1, y = 1;

int main() {
	cin >> N;
	N--;
	cin >> fir;
	while (N--) {
		cin >> rot;
		fir *= x;
		rot *= y;
		int t = y;
		cout << fir / gcd(fir, rot) << "/" <<  rot / gcd(fir, rot) << endl;
		x = fir / gcd(fir, rot);
		y = rot / gcd(fir, rot);
		fir = rot / t;
	}

	return 0;
}