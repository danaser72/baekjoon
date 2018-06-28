#include <iostream>
using namespace std;

int N;
int MAX = 0;
int arr[100002] = { 0, };
int cnt = 0;

int main() {
	cin >> N;

	int t;

	for (int i = 0; i < 2 * N; i++) {
		scanf("%d", &t);

		if (arr[t] == 0) {
			arr[t] = 1;
			cnt++;

			if (MAX < cnt) {
				MAX = cnt;
			}
		}
		else if (arr[t] == 1) {
			arr[t] = -1;
			cnt--;
		}
	}

	cout << MAX << endl;

	return 0;
}