#include <iostream>
using namespace std;

int N;
int arr[1001];

void fn(int f, int l);

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	fn(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}

void fn(int f, int l) {
	int pivot = f;
	int i = f + 1, j = f;

	if (f >= l)
		return;

	while (i <= l) {
		if (arr[i] <= arr[pivot]) {
			j++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		i++;
	}
	int temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;
	pivot = j;

	fn(f, pivot - 1);
	fn(pivot + 1, l);
}