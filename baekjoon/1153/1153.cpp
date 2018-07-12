#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> prime;
bool chk[1000002] = { 0, };
int N;
int ans[4] = { 0,0,0,0 };

bool func(int pos, int val);

int main() {
	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (!chk[i])
			prime.push_back(i);
		for (int j = 2; j * i <= N; j++) {
			chk[i*j] = true;
		}
	}

	if (!func(0, N)) {
		cout << "-1" << endl;
	}

	return 0;
}


bool func(int pos, int val) {
	if (pos == 4) {
		if (!val) {
			sort(ans, ans + 4);
			for (int i = 0; i < 4; i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		return !val;
	}

	if (val <= 0)
		return false;

	bool check = false;

	for (int i = prime.size() - 1; i >= 0 && !check; i--) {
		ans[pos] = prime[i];
		check = func(pos + 1, val - prime[i]);
	}

	return check;
}