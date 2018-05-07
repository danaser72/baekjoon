#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int t, N, M, W;
int S, E, T;

int func();

int main() {
	cin >> t;

	for (int n = 0; n < t; n++) {
		int check = func();

		if (check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

int func() {
	int check = 0;
	cin >> N >> M >> W;
	vector<pair<int, int>> v[502];
	int w[502][502];

	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;

		v[S].push_back({ E, T });
		v[E].push_back({ S, T });
	}

	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;

		v[S].push_back({ E, -1 * T });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			w[i + 1][j + 1] = INT_MAX;
		}
	}
	int upd = 1;

	while (upd) {
		upd = 0;

		w[1][1] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (w[1][v[i][j].first] > v[i][j].second + w[1][i]) {
					if (w[1][i] != INT_MAX) {
						w[1][v[i][j].first] = v[i][j].second + w[1][i];
						upd = 1;
					}
				}
			}
		}
		if (w[1][1] < 0) {
			check = 1;
			break;
		}
	}

	return check;
}