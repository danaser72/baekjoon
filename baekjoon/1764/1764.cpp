#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int cnt = 0;
string arr[1000004];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + (N + M));

	for (int i = 0; i < N + M - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt++;
		}
	}

	cout << cnt << endl;
	for (int i = 0; i < N + M - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			cout << arr[i] << endl;
		}
	}

	return 0;
}