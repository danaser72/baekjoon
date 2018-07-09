#include <iostream>
#include <vector>
using namespace std;

int T, N;
int arr[45] = { 1, 1, };

int main() {
	for (int i = 2; i < 45; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cin >> T;
	while (T--) {
		cin >> N;

		vector<int> v;
		long long val = 0;

		for (int i = 44; i >= 0; i--) {
			if (val + arr[i] <= N) {
				val += arr[i];
				v.push_back(arr[i]);

				if (val == N)
					break;
			}
		}

		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	return 0;
}