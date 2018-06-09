#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, W;
vector<int> v;
int dp[1002][31] = { 0, };
int MAX = 0;

int main() {
	cin >> T >> W;

	for (int i = 0; i < T; i++) {
		int tree;
		scanf("%d", &tree);

		v.push_back(tree);
	}

	for (int i = 1; i <= T; i++) {
		if (v[i - 1] == 1) {
			for (int j = W; j >= 0; j--) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				if ((W - j) % 2 == 0) {
					dp[i][j] ++;
				}
			}
		}
		else {
			for (int j = W; j >= 0; j--) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				if ((W - j) % 2 == 1) {
					dp[i][j] ++;
				}
			}
		}
	}

	printf("%d\n", dp[T][0]);

	return 0;
}