#include <iostream>
#include <map>
#include <string>
using namespace std;

string str;

int main() {
	while (1) {
		cin >> str;

		if (!str.compare("*"))
			break;

		bool chk = false;

		for (int i = 1; i < str.size() && !chk; i++) {
			map<string, bool> m;
			map<string, bool>::iterator it;

			for (int j = 0; j + i < str.size(); j++) {
				string k;
				k = str[j];
				k += str[j + i];

				it = m.find(k);

				if (it != m.end()) {
					chk = true;
	 				break;
				}
				else {
					m[k] = true;
				}
			}
		}

		if (chk) {
			cout << str << " is NOT surprising." << endl;
		}
		else {
			cout << str << " is surprising." << endl;
		}
	}

	return 0;
}