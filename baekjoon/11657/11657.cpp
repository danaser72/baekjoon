#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N, M;
int A, B, C;
int func();

int main() {
	cin >> N >> M;

	vector<pair<int, int>> v[502];
	int w[502];

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}

	for (int i = 0; i < N; i++) {
			w[i + 1] = INT_MAX;
	}

	int check = 0;

	w[1] = 0;
	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (w[v[i][j].first] > w[i] + v[i][j].second) {
					if (w[i] != INT_MAX) {
						w[v[i][j].first] = w[i] + v[i][j].second;
						if (k == N) {
							check = 1;
						}
					}
				}
			}
		}
	}

	if (!check) {
		for (int i = 2; i <= N; i++) {
			if (w[i] == INT_MAX) {
				w[i] = -1;
			}
			cout << w[i] << endl;
		}
	}
	else {
		cout << "-1" << endl;
	}
	return 0;
}