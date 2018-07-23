#include <iostream>
using namespace std;

int N, K;
int num = 0;
bool chk = false;
bool prime[1002] = { 0, };

int main() {
	cin >> N >> K;

	for (int i = 2; i <= N && !chk; i++) {
		if (!prime[i]) {
			for (int j = 1; j * i <= N; j++) {
				if (prime[j * i]) {
					continue;
				}
				K--;
				prime[j * i] = true;

				if (!K) {
					num = j * i;
					break;
				}
			}
		}
	}

	cout << num << endl;

	return 0;
}