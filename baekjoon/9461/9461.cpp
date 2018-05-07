#include <iostream>
using namespace std;

long long arr[101] = { 1, 1, 1 };

long long fib(int a);

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << fib(N - 1) << endl;
	}


	return 0;
}


long long fib(int a) {
	if (a == 0 || a == 1 || a == 2) {
		return arr[0];
	}
	else if (arr[a - 2] == 0 || arr[a - 3] == 0) {
		return fib(a - 2) + fib(a - 3);
	}
	else {
		arr[a] = arr[a - 2] + arr[a - 3];
		return arr[a];
	}
}