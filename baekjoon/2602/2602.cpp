#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

string scroll;
string stone[2];
long long dp[2][105][22];

long long func(int x, int y, int z) {
	long long ret = 0;

	if (y == stone[0].size() && z != scroll.size())
		return 0;
	if (z == scroll.size())
		return 1;

	if (dp[x][y][z] != -1)
		return dp[x][y][z];

	for (int i = y; i < stone[0].size(); i++) {
		if (stone[x][i] == scroll[z]) {
			ret += func((x + 1) % 2, i + 1, z + 1);
		}
	}

	dp[x][y][z] = ret;

	return ret;
}



int main() {
	cin >> scroll >> stone[0] >> stone[1];

	memset(dp, -1, sizeof(dp));

	cout << func(0, 0, 0) + func(1, 0, 0) << endl;

	return 0;
}