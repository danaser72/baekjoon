#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string str;
string del = "CAMBRIDGE";

int main() {
	cin >> str;
	bool chk;

	for (int i = 0; i < str.size(); i++) {
		chk = false;
		for (int j = 0; j < del.size(); j++) {
			if (str[i] == del[j]) {
				chk = true;
				break;
			}
		}
		if (!chk)
			cout << str[i];
	}
	cout << endl;
	return 0;
}