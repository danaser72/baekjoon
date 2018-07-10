#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
int score, award;

int main() {
	cin >> T;

	while (T--) {
		vector<pair<int, int>> v;

		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &score, &award);

			v.push_back({ score, award });
		}

		sort(v.begin(), v.end());

		int cnt = 1;
		int MAX = v[0].second;

		for (int i = 1; i < N; i++) {
			if (MAX > v[i].second) {
				cnt++;
				MAX = v[i].second;
			}
		}


		cout << cnt << endl;
	}

	return 0;
}