#include <iostream>
using namespace std;

int T;
int N, K;
int candy;
int cnt;

int main() {
	cin >> T;

	while (T--) {
		cnt = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> candy;

			cnt += (candy / K);
		}
		cout << cnt << endl;
	}

	return 0;
}