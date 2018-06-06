#include <iostream>
using namespace std;

int N;
int x, y;
int arr[5] = { 0, };

int main() {
	cin >> N;
	while (N--) {
		scanf("%d%d", &x, &y);

		if (x == 0 || y == 0) {
			arr[4] ++;
		}
		else if (x > 0 && y > 0) {
			arr[0] ++;
		}
		else if (x < 0 && y > 0) {
			arr[1] ++;
		}
		else if (x < 0 && y < 0) {
			arr[2] ++;
		}
		else if (x > 0 && y < 0) {
			arr[3] ++;
		}
	}
	cout << "Q1: " << arr[0] << endl
		<< "Q2: " << arr[1] << endl
		<< "Q3: " << arr[2] << endl
		<< "Q4: " << arr[3] << endl
		<< "AXIS: " << arr[4] << endl;

	return 0;
}