#include <iostream>
using namespace std;

int N;
long long Y = 0;
long long M = 0;

int main() {
	cin >> N;

	int val;
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);

		Y += 10 * ((val + 30) / 30);
		M += 15 * ((val + 60) / 60);
	}

	if (Y < M) {
		cout << "Y " << Y << endl;
	}
	else if (Y > M) {
		cout << "M " << M << endl;
	}
	else {
		cout << "Y M " << Y << endl;
	}

	return 0;
}