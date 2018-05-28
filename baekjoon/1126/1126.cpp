/*
** reference : http://junh0.tistory.com/2
*/

#include <iostream>
using namespace std;

#define MAX 500002
int N;
int arr[52];
int dp[52][MAX] = { 0, };

void func();

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= MAX; i++)
		dp[0][i] = -1;

	func();

	if (dp[N][0] != 0)
		cout << dp[N][0] << endl;
	else
		cout << "-1" << endl;

	return 0;
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX; j++) {
			// ������ �ȵ� ���
			dp[i][j] = dp[i - 1][j];

			// ���ԵǾ�, �������� j
			// ���� h1�� ������ ����(���� �������� j - arr[i])
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][j - arr[i]] + arr[i] ? dp[i][j] : dp[i - 1][j - arr[i]] + arr[i];
			}
			// ���� h2�� �����Ͽ�, h1�� ����(���� �������� arr[i] - j)
			if (j - arr[i] <= 0 && dp[i - 1][arr[i] - j] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][arr[i] - j] + j ? dp[i][j] : dp[i - 1][arr[i] - j] + j;
			}
			// ���� h2�� ����������, h2�� ���� (���� �������� j + arr[i])
			if (j + arr[i] <= MAX && dp[i - 1][j + arr[i]] != -1) {
				dp[i][j] = dp[i][j] > dp[i - 1][j + arr[i]] ? dp[i][j] : dp[i - 1][j + arr[i]];
			}
		}
	}
}