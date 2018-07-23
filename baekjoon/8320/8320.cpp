#include <iostream>
using namespace std;

int n;
int cnt = 0;
bool rec[10002][10002] = { 0, };

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * i <= n; j++) {
			int x = i;
			int y = j;
			if (x < y) {
				if (!rec[x][y]) {
					rec[x][y] = true;
					cnt++;
				}
			}
			else {
				if (!rec[y][x]) {
					rec[y][x] = true;
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}