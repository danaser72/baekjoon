#include <iostream>
#include <vector>
using namespace std;

int N, M;
int v[100002];
int dp[100002] = { 0, };

int main() {
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		//cin >> v[i];
		scanf("%d", &v[i]);
		dp[i] = dp[i - 1] + v[i];
	}

	int x, y;
	for (int i = 0; i < M; i++) {
		//cin >> x >> y;
		scanf("%d%d", &x, &y);
		if (x > y) {
			int t = x;
			x = y;
			y = t;
		}
		printf("%d\n", dp[y] - dp[x - 1]);
	}

	return 0;
}