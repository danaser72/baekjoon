#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100002];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] * (N - i);
	}

	sort(arr, arr + N);

	cout << arr[N - 1] << endl;

	return 0;
}