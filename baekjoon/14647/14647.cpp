#include <iostream>
using namespace std;

int n, m;
int arr[503][503] = { 0, };
int all = 0;
int MAX = 0;

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		int row = 0;
		for (int j = 0; j < m; j++) {
			int t, cnt = 0;
			scanf("%d", &t);

			if (t / 1000 == 9)
				cnt++;
			t %= 1000;

			if (t / 100 == 9)
				cnt++;
			t %= 100;

			if (t / 10 == 9)
				cnt++;

			if (t % 10 == 9)
				cnt++;

			all += cnt;
			row += cnt;
			arr[i][j] = cnt;
		}
		if (row > MAX)
			MAX = row;
	}

	for (int j = 0; j < m; j++) {
		int col = 0;
		for (int i = 0; i < n; i++) {
			col += arr[i][j];
		}
		if (col > MAX)
			MAX = col;
	}

	printf("%d\n", all - MAX);

	return 0;
}