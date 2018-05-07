#include <iostream>
using namespace std;

int M, F;

int main() {
	while (1) {
		cin >> M >> F;

		if (!M && !F)
			break;

		cout << M + F << endl;
	}
	return 0;
}