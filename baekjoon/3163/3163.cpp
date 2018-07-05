#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, L, k;

int main() {
	cin >> T;

	while (T--) {
		int ans = 0;
		vector<pair<int, int>> v;

		vector<int> dot;
		cin >> N >> L >> k;

		int p, a;
		for (int i = 0; i < N; i++) {
			cin >> p >> a;

			if (a > 0) {
				p = L - p;
				v.push_back({ p, a });
			}
			else {
				v.push_back({ p, a });
			}
			
			dot.push_back(a);
		}

		int left = 0;
		int right = v.size() - 1;

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (v[i].second > 0) {
				v[i].second = dot[right];
				right--;
			}
			else {
				v[i].second = dot[left];
				left++;
			}
		}

		sort(v.begin(), v.end());

		cout << v[k - 1].second << endl;
	}

	return 0;
}