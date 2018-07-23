#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int MIN = 0;

void func(int cnt, vector<int> v) {
	if (v[0] == v[1] || v[1] == v[2]) {
		MIN = cnt - 1 > MIN ? cnt - 1 : MIN;
	}
	else {
		vector<int> a = v;
		a[0] = a[1] + 1;
		sort(a.begin(), a.end());
		func(cnt + 1, a);

		a = v;
		a[2] = a[1] - 1;
		sort(a.begin(), a.end());
		func(cnt + 1, a);
	}
}

int main() {
	vector<int> v;

	for (int i = 0; i < 3; i++) {
		cin >> N;

		v.push_back(N);
	}

	func(0, v);

	cout << MIN << endl;

	return 0;
}