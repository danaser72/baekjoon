/*
** ref : http://mygumi.tistory.com/126
*/

#include <iostream>
#include <string>
using namespace std;

string A, B;
int dp[1002][1002] = { 0, };

int main() {
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}

	cout << dp[A.size()][B.size()] << endl;

	return 0;
}