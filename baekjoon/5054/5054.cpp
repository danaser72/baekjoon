#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n;
int arr[21];

int main() {
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);

		cout << (arr[n - 1] - arr[0]) * 2 << endl;
	}

	return 0;
}