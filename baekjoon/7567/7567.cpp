#include <iostream>
#include <string>
using namespace std;

string str;
int pos = -1;
int h = 0;

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (pos != str[i]) {
			pos = str[i];
			h += 10;
		}
		else {
			h += 5;
		}
	}

	cout << h << endl;

	return 0;
}