#include <iostream>
#include <algorithm>
using namespace std;

int x, y;

void conv_56(int &num);
void conv_65(int &num);

int arr[4] = { 0, };

int main() {
	cin >> x >> y;
	conv_56(x);
	conv_56(y);
	arr[0] = x + y;
	conv_65(y);
	arr[1] = x + y;
	conv_65(x);
	arr[3] = x + y;
	conv_56(y);
	arr[2] = x + y;

	sort(arr, arr + 4);

	cout << arr[0] << " " << arr[3] << endl;

	return 0;
}

void conv_56(int &num) {
	int t = num;
	int ten;
	for (int i = 1; t != 0; i++) {
		ten = 1;
		if (t % 10 == 5) {
			for (int j = 1; j < i; j++) {
				ten *= 10;
			}
			num += ten;
		}
		t /= 10;
	}
}
void conv_65(int &num) {
	int t = num;
	int ten;
	for (int i = 1; t != 0; i++) {
		ten = 1;
		if (t % 10 == 6) {
			for (int j = 1; j < i; j++) {
				ten *= 10;
			}
			num -= ten;
		}
		t /= 10;
	}
}