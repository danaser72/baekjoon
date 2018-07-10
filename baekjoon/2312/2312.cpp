#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

bool arr[100003] = { 0, };
vector<int> prime;

int main() {
	for (int i = 2; i <= 100000; i++) {
		if (!arr[i]) {
			prime.push_back(i);

			for (int j = 2; j * i <= 100000; j++) {
				arr[i*j] = true;
			}
		}
	}

	cin >> T;
	while (T--) {
		int cnt[10000] = { 0, };

		cin >> N;

		while (N != 1) {
			for (int i = 0; i < prime.size(); i++) {
				if (N % prime[i] == 0) {
					cnt[i]++;
					N /= prime[i];
					break;
				}
			}
		}

		for (int i = 0; i < prime.size(); i++) {
			if (cnt[i]) {
				cout << prime[i] << " " << cnt[i] << "\n";
			}
		}
	}
	return 0;
}