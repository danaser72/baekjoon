#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> t;

int main() {
	cin >> N;

	int num;
	vector<int>::iterator it;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = N - 1; i >= 0; i--) {
		it = lower_bound(t.begin(), t.end(), v[i]);

		if (it != t.end()) {
			*it = v[i];
		}
		else {
			t.push_back(v[i]);
		}
	}

	cout << t.size() << endl;

	return 0;
}