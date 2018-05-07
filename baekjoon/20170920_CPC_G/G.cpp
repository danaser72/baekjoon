#include <iostream>
using namespace std;

int N;
int arr[501][501] = { 0, };
int x_1, x_2, y_1, y_2;
int maxs = 0;

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		for (int i = x_1; i < x_2; i++) {
			for (int j = y_1; j < y_2; j++) {
				if (!arr[i][j]) {
					arr[i][j] = 1;
					maxs++;
				}
			}
		}
	}

	cout << maxs << endl;

	return 0;
}