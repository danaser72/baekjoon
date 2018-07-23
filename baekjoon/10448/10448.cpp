#include <iostream>
using namespace std;

int T;
int arr[1002] = { 0, };
bool chk;
bool func(int pos, int num) {
	if (pos == 0) {
		chk = num == 0;
		return chk;
	}

	if (chk)
		return true;

	for (int i = 1000; i >= 1 && !chk; i--) {
		if (arr[i] <= num)
			chk = func(pos - 1, num - arr[i]);
	}
	
	return chk;
}

int main() {
	cin >> T;

	for (int i = 1; i <= 1000; i++) {
		arr[i] = i * (i + 1) / 2;
	}

	while (T--) {
		chk = false;
		int num;
		cin >> num;
	
		cout << func(3, num) << endl;
	}

	return 0;
}