#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Memorization

int n;
vector <vector< pair<int, int>>> v;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int func(int x, int y);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector <pair<int, int>> tmp;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			tmp.push_back({ t,0 });
		}
		v.push_back(tmp);
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
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j].second << " ";
		}
		cout << endl;
	}*/

	cout << MAX << endl;

	return 0;
}

int func(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 1 });

	int MAX = 0;

	while (!q.empty()) {
		int _x = q.front().first.first, _y = q.front().first.second, val = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (_x == -1)
				continue;
			else if (_x + dx[i] >= 0 && _x + dx[i] < n && _y + dy[i] >= 0 && _y + dy[i] < n) {
				if (v[_x][_y].first < v[_x + dx[i]][_y + dy[i]].first) {
					if (v[_x + dx[i]][_y + dy[i]].second != 0) {
						q.push({ { -1, -1 }, val + v[_x + dx[i]][_y + dy[i]].second });
					}
					else {
						q.push({ { _x + dx[i], _y + dy[i] }, val + 1 });
					}
				}
			}
		}
		if (MAX < val)
			MAX = val;
	}

	return MAX;
	/*
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
	*/
}