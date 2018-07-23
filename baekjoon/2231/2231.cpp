#include <iostream>
using namespace std;

int N;
int ans = 0;

int main() {
	cin >> N;

	int i;

	for (i = N; i > 0; i--) {
		int m = i;
		int n = i;

		while (n) {
			m += n % 10;
			n /= 10;
		}

		if (N == m) {
			ans = i;
		}
	}
	
	cout << ans << endl;

	return 0;
}