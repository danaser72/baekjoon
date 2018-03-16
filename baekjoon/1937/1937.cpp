#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector <pair<int, int>> v[502];

int func(int x, int y);

int main() {
	cin >> n;

	for (int i = 0; i < n*n; i++) {
		int t;
		cin >> t;
		v[i / n].push_back({ t, 0 });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j].second = func(i, j);
		}
	}

	int MAX = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].second > MAX) {
				MAX = v[i][j].second;
			}
		}
	}

	cout << MAX << endl;

	return 0;
}

int func(int x, int y) {
	int check = 0;
	if (v[x][y].second != 0)
		return v[x][y].second;

	int a = 0, b = 0, c = 0, d = 0;
	//queue

	if (x > 0 && v[x][y].first < v[x - 1][y].first) {
		a = func(x - 1, y);
		check = 1;
	}
	if (y > 0 && v[x][y].first < v[x][y - 1].first) {
		b = func(x, y - 1);
		check = 1;
	}
	if (x < n - 1 && v[x][y].first < v[x + 1][y].first) {
		c = func(x + 1, y);
		check = 1;
	}
	if (y < n - 1 && v[x][y].first < v[x][y + 1].first) {
		d = func(x, y + 1);
		check = 1;
	}

	if (!check) {
		return 1;
	}

	a = a > b ? a : b;
	c = c > d ? c : d;
	return a > c ? a + 1 : c + 1;
}