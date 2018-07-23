#include <iostream>
#include <string>
using namespace std;

int cup[4] = { 1,0,0,2 };
string str;

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		int t;
		if (str[i] == 'A') {
			t = cup[0];
			cup[0] = cup[1];
			cup[1] = t;
		}
		else if (str[i] == 'B') {
			t = cup[0];
			cup[0] = cup[2];
			cup[2] = t;
		}
		else if (str[i] == 'C') {
			t = cup[0];
			cup[0] = cup[3];
			cup[3] = t;
		}
		else if (str[i] == 'D') {
			t = cup[1];
			cup[1] = cup[2];
			cup[2] = t;
		}
		else if (str[i] == 'E') {
			t = cup[1];
			cup[1] = cup[3];
			cup[3] = t;
		}
		else if (str[i] == 'F') {
			t = cup[2];
			cup[2] = cup[3];
			cup[3] = t;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (cup[i] == 1) {
			cout << i + 1 << endl;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (cup[i] == 2) {
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}