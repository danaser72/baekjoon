#include <iostream>
using namespace std;

int n, m;
char arr[1005][1005];
int dp[1002][1002] = { 0, };
int MAX = 0;

int main() {
	cin >> n >> m;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == '1') {
				int a = dp[i][j - 1] < dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];

				a = a < dp[i - 1][j - 1] ? a : dp[i - 1][j - 1];

				dp[i][j] = a + 1;

				MAX = dp[i][j] > MAX ? dp[i][j] : MAX;
			}
		}
	}

	cout << MAX * MAX << endl;

	return 0;
}