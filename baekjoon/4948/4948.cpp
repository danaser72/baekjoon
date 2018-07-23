#include <iostream>
#include <vector>
using namespace std;

#define MAX 246915

int n;

bool arr[MAX] = { 0, };
vector<int> prime;

int main() {
	for (int i = 2; i < MAX; i++) {
		if (!arr[i]) {
			prime.push_back(i);

			for (int j = 2; j * i < MAX; j++) {
				arr[i * j] = true;
			}
		}
	}

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		int cnt = 0;

		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] > n && prime[i] <= 2 * n) {
				cnt++;
			}
			if (prime[i] > 2 * n)
				break;
		}

		cout << cnt << endl;
	}

	return 0;
}