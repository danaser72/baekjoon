#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000000

vector<int> prime;
bool num[MAX] = { 0, };
int N;

int main() {
	for (int i = 2; i < MAX; i++) {
		if (!num[i]) {
			prime.push_back(i);

			for (int j = 2; j * i < MAX; j++) {
				num[i*j] = true;
			}
		}
	}

	cin >> N;

	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] < N)
			continue;

		bool chk = true;
		int t = prime[i];
		int pos = 0;
		char n[8];
		while (t) {
			n[pos++] = t % 10 + '0';
			t /= 10;
		}

		for (int j = 0; j < pos / 2; j++) {
			if (n[j] != n[pos - j - 1]) {
				chk = false;
				break;
			}
		}
		if (chk) {
			cout << prime[i] << endl;
			break;
		}
	}

	return 0;
}