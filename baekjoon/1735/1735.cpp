#include <iostream>
using namespace std;

int A, B, C, D;
int ansA, ansB;

int main() {
	cin >> A >> B >> C >> D;

	ansB = B * D;
	ansA = A * D + B * C;

	for (int i = 2; i <= ansB; i++) {
		if (ansB % i == 0 && ansA % i == 0) {
			ansA /= i;
			ansB /= i;
			i--;
		}
	}

	cout << ansA << " " << ansB << "\n";

	return 0;
}