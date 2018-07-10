#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> v;

int A, B;

int main() {
	cin >> A >> B;

	int t;
	for (int i = 0; i < A; i++) {
		scanf("%d", &t);
		v.push_back(t);
		cnt++;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < B; i++) {
		scanf("%d", &t);
		int s = 0;
		int e = v.size() - 1;
		int m;

		while (s <= e) {
			m = (s + e) / 2;
			if (v[m] > t) {
				e = m - 1;
			}
			else if (v[m] < t) {
				s = m + 1;
			}
			else {
				cnt -= 2;
				break;
			}
		}
		cnt++;
	}
	
	cout << cnt << endl;

	return 0;
}