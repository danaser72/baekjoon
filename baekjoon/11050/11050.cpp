#include <iostream>
using namespace std;

int N, K;

int p[11][11] = { 0, };

int main() {
	cin >> N >> K;

	for (int i = 0; i <= 10; i++) {
		p[i][0] = 1;
		p[i][i] = 1;
	}

	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j < i; j++) {
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
		}
	}

	cout << p[N][K] << endl;

	return 0;
}