#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10002] = { 0, };

int func();

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;

	sort(arr, arr + N);

	cout << func() << endl;

	return 0;
}

int func() {
	int s = 1, e = arr[N - 1];
	int m;

	while (s <= e) {
		m = (s + e) / 2;

		int val = 0;

		for (int i = 0; i < N; i++) {
			if (arr[i] > m)
				val += m;
			else
				val += arr[i];
		}

		if (val == M)
			return m;
		else if (val > M)
			e = m - 1;
		else if (val < M)
			s = m + 1;
	}
	return e;
}