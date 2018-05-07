#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i]++;
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		arr[i] += N - i;
	}

	sort(arr, arr + N);

	cout << arr[N - 1] << endl;

	return 0;
}