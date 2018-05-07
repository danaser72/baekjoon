#include <iostream>
using namespace std;

int T;
char num[18];
int odd[9];
int even[9];

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		int val = 0;

		cin >> num;

		for (int j = 0; j < 8; j++) {
			odd[j] = (num[j * 2 + 1] - '0');
			int t = (num[j * 2] -'0') * 2;
			if (t >= 10)
				even[j] = t - 9;
			else
				even[j] = t;
		}

		for (int j = 0; j < 8; j++) {
			val += even[j] + odd[j];
		}

		if (!(val % 10))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}