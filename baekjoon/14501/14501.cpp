#include <iostream>
using namespace std;

int N;
int dp[1 << 16][2] = {};
int MAX = 0;

int main() {
	cin >> N;
	int k = 0;
	int m = 0;

	int t, p;
	for (int i = 0; i < N; i++) {
		//cin >> t >> p;
		scanf("%d%d", &t, &p);
		if (t + i > N) {
			continue;
		}
		for (int j = 0; j < k + 1; j++) {
			if (dp[j][0] == 0 && dp[j][1] == 0) {
				dp[j][0] = i + t;
				dp[j][1] = p;
				if (dp[j][1] > MAX)
					MAX = dp[j][1];
			} else if (dp[j][0] <= i) {
				dp[k][0] = i + t;
				dp[k][1] = dp[j][1] + p;
				if (dp[k][1] > MAX)
					MAX = dp[k][1];
				k++;
			}
		}
		k++;
	}

	//cout << MAX << endl;
	printf("%d\n", MAX);

	return 0;
}