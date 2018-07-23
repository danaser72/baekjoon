#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;
bool chk = false;

void func(int k, int cnt) {
	if (k == 0) {
		cout << cnt << endl;
		chk = true;
	}

	if (chk) {
		return;
	}

	for (int i = N - 1; i >= 0 && !chk; i--) {
		if (v[i] <= k) {
			func(k % v[i], cnt + k / v[i]);
		}
	}
}

int main() {
	cin >> N >> K;

	int coin;
	for (int i = 0; i < N; i++) {
		cin >> coin;

		v.push_back(coin);
	}

	func(K, 0);

	return 0;
}