#include <iostream>
using namespace std;

int N, K;
int arr[1002][3];
int cnt = 0;

int main() {
	cin >> N >> K;

	int cont;

	for (int i = 0; i < N; i++) {
		cin >> cont;

		cin >> arr[cont][0] >> arr[cont][1] >> arr[cont][2];
	}

	for (int i = 1; i <= N; i++) {
		if (K == i)
			continue;

		if (arr[i][0] > arr[K][0]) {
			cnt++;
		}
		else if (arr[i][0] == arr[K][0]) {
			if (arr[i][1] > arr[K][1]) {
				cnt++;
			}
			else if (arr[i][1] == arr[K][1]) {
				if (arr[i][2] > arr[K][2]) {
					cnt++;
				}
			}
		}
	}

	cout << cnt + 1 << endl;

	return 0;
}