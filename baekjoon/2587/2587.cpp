#include <iostream>
#include <algorithm>
using namespace std;

int arr[6] = {0, };
int sum = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 5);

	cout << sum / 5 << endl << arr[2] << endl;

	return 0;
}