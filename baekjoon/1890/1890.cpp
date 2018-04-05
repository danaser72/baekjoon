#include <iostream>
using namespace std;

int N, cnt = 0;
int arr[103][103] = { 0, };
long dp[103][103] = { 0, };

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	
	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int add = arr[i][j];
			int x = i + add, y = j + add;

			if (x < N && i != N - 1)
				dp[x][j] += dp[i][j];
			if (y < N && j != N - 1)
				dp[i][y] += dp[i][j];
		}
	}


	cout << dp[N - 1][N - 1] << endl;

	return 0;
}