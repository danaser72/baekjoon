#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, K;
vector<long long> v;
int ans = 0;

void func();

int main() {
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		int t;

		scanf("%d", &t);
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	func();

	return 0;
}

void func() {
	long long first = 0, last = v[K - 1];
	long long mid;
	long long ans = 0;

	while (first <= last) {
		long long sum = 0;
		mid = (first + last + 1) / 2;

		for (int i = 0; i < K; i++) {
			sum += v[i] / mid;
		}

		if (sum >= N) {
			first = mid + 1;
			ans = mid;
		}
		else if (sum < N) {
			last = mid - 1;
		}
	}

	cout << ans << endl;
}