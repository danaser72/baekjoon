#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N;

int main() {
	cin >> T;
	
	while (T--) {
		cin >> N;

		int dp[10005];
		vector<int> v;
		vector<int> L;

		int l;
		for (int i = 0; i < N; i++) {
			cin >> l;
			v.push_back(l);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < N; i++) {
			if (i % 2 == 0)
				L.push_back(v[i]);
		}

		for (int i = N - 1; i >= 0; i--) {
			if (i % 2 == 1)
				L.push_back(v[i]);
		}

		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				dp[i] = (L[i] - L[0]) < 0 ? -(L[i] - L[0]) : (L[i] - L[0]);
			}
			else {
				dp[i] = (L[i] - L[i + 1]) < 0 ? -(L[i] - L[i + 1]) : (L[i] - L[i + 1]);
			}
		}
		sort(dp, dp + N);

		cout << dp[N - 1] << endl;
	}

	return 0;
}