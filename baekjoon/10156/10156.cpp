#include <iostream>
using namespace std;

long long K, N, M;

int main() {
	cin >> K >> N >> M;

	if (K * N - M <= 0) {
		cout << "0" << endl;
	}
	else {
		cout << K * N - M << endl;
	}

	return 0;
}