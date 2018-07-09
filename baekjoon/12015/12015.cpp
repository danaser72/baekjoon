#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
	cin >> N;


	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
		if (it != v.end()) {
			*it = num;
		}
		else {
			v.push_back(num);
		}
	}

	cout << v.size() << endl;

	return 0;
}