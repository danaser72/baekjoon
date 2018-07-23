#include <iostream>
#include <string>
using namespace std;

int SIZE;
string str;

bool func(int p) {
	for (int i = p; i < str.size(); i++) {
		if (str[i] != str[SIZE - i - 1]) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> str;

	int len = -1;

	SIZE = str.size();
	for (int i = 0; i < str.size(); i++) {
		int p = SIZE / 2;
		if (func(p)) {
			len = str.size() + (str.size() - 1 - p);
			break;
		}
		SIZE++;
	}

	cout << SIZE << endl;

	return 0;
}