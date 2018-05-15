#include <iostream>
using namespace std;

int n, m;
int dp[1002][1002] = { 0, };
int rem = 1000000007;

int func(int x, int y);

int main() {
	cin >> n >> m;
	
	dp[1][1] = 1;
	cout << func(n, m) << endl;

	return 0;
}

int func(int x, int y) {
	if (dp[x][y])
		return dp[x][y];

	long long a, b, c;
	if (x == 1) {
		a = 0;
		b = func(x, y - 1);
		c = 0;
	}
	else if (y == 1) {
		a = func(x - 1, y);
		b = 0;
		c = 0;
	}
	else{
		a = func(x - 1, y);
		b = func(x, y - 1);
		c = func(x - 1, y - 1);
	}

	dp[x][y] = (a + b + c) % rem;

	return dp[x][y];
}