#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
using namespace std;

int N;
vector <pair<int, int>> v;
int dp[502][502];

int min(int a, int b) {
	return a < b ? a : b;
}

int func(int x, int y);

int main() {
	cin >> N;

	memset(dp, -1, sizeof(dp));
	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;

		v.push_back({ r,c });
	}

	cout << func(0, N - 1) << endl;

	return 0;
}

int func(int x, int y) {
	if (x == y)
		return 0;

	int ret = dp[x][y];

	if (ret > 0)
		return dp[x][y];

	ret = INT_MAX;

	for (int i = x; i < y; i++) {
		ret = min(ret, func(x, i) + func(i + 1, y) + v[x].first * v[i].second * v[y].second);
	}

	dp[x][y] = ret;

	return ret;
}