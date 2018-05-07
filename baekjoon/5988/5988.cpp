#include <iostream>
#include <string.h>
using namespace std;

int N;

int main() {
	cin >> N;

	for (int i = 0 ; i < N ; i++){
		char K[65];
		cin >> K;

		if (K[strlen(K) - 1] % 2) {
			cout << "odd" << endl;
		}
		else {
			cout << "even" << endl;
		}
	}

	return 0;
}