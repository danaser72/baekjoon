#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string str;
char c[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (str[i] == c[j]) {
				str.erase(str.begin() + 1 + i);
				str.erase(str.begin() + 1 + i);
				break;
			}
		}
	}

	cout << str << endl;

	return 0;
}