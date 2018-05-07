#include <iostream>
using namespace std;

int N;
int T;
int arr[101][2] = { 0, };
long long dfs(int ind, int allT);

int main() {
	cin >> N >> T;

	for (int k = 0; k < N; k++) {
		cin >> arr[k][0] >> arr[k][1];
	}

	cout << dfs(0, 0) << endl;

	return 0;
}

long long dfs(int ind, int allT) {
	if (ind >= N) {
		return 0;
	}
	else {
		long long t1 = 0, t2, ret;
		if (allT + arr[ind][0] <= T) {
			t1 = dfs(ind + 1, allT + arr[ind][0]) + arr[ind][1];
		}
		ret = dfs(ind + 1, allT);

		ret = t1 > t2 ? t1 : t2;

		return ret;
	}
}