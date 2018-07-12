#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
long long MIN, MAX;
bool arr[1000002] = { 0, };

int main() {
	cin >> MIN >> MAX;

	long long i = 2;

	while (i * i <= MAX) {
		v.push_back(i * i);
		i++;
	}

	for (int i = 0; i < v.size(); i++) {
		for (long long j = MIN / v[i]; j <= MAX / v[i]; j++) {
			if (j * v[i] < MIN)
				continue;
			arr[j * v[i] - MIN] = true;
		}
	}

	int cnt = 0;
	for (long long i = 0; i < MAX - MIN + 1; i++) {
		if (!arr[i]) {
			//printf("%lld ", i + MIN);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}