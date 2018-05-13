/*
** referece http://huiyu.tistory.com/entry/DP-01-Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
pair<int, int> TS[1002];
int dp[10002] = { 0, };

int main() {
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> TS[i].first >> TS[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = T; j >= TS[i].first; j--) {
			dp[j] = max(dp[j], dp[j - TS[i].first] + TS[i].second);
		}
	}

	cout << dp[T] << endl;

	return 0;
}