#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
	cin >> N;

	int t;

	for (int i = 1; i <= N; i++) {
		cin >> t;

		v.insert(v.end() - t, i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}