#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
		else {
			str[i] = str[i] - 'a' + 'A';
		}
	}

	cout << str << endl;

	return 0;
}