#include <iostream>
#include <string>
using namespace std;

string num;
int type;

int func() {
	int val;
	int mul = 1;
	int ret = 0;

	if (type == 0)
		val = 10;
	else if (type == 1)
		val = 8;
	else
		val = 16;

	for (int i = num.size() - 1; i >= type; i--) {
		if (type == 2) {
			if (num[i] < '0' || num[i] > '9') {
				ret += (num[i] - 'a' + 10) * mul;
				mul *= val;
			}
			else {
				ret += (num[i] - '0') * mul;
				mul *= val;
			}
		}
		else {
			ret += (num[i] - '0') * mul;
			mul *= val;
		}
	}

	return ret;
}

int main() {
	cin >> num;
	if (num[0] != '0') {
		type = 0;
	}
	else {
		if (num[1] != 'x') {
			type = 1;
		}
		else {
			type = 2;
		}
	}

	cout << func() << endl;

	return 0;
}