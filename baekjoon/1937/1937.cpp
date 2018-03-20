#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Memorization

int n;
vector <int> v[502];
int dp[502][502] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int func(int x, int y);

int main() {
	cin >> n;
	int MAX = 0;

	for (int i = 0; i < n*n; i++) {
		int t;
		cin >> t;
		v[i / n].push_back(t);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = func(i, j);
			MAX = MAX > t ? MAX : t;
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j].second << " ";
		}
		cout << endl;
	}*/

	cout << MAX << endl;

	return 0;
}

int func(int x, int y) {
	if (dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (v[x][y] < v[nx][ny]) {
				int t = func(nx, ny) + 1;
				dp[x][y] = dp[x][y] > t ? dp[x][y] : t;
			}
		}
	}

	return dp[x][y];
}