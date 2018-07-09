#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int N;
string name, record;
map<string, bool> m;
//map<string, bool, greater<string>> m;

int main() {
	cin >> N;
	map<string, bool>::iterator it;
	while (N--) {
		cin >> name >> record;

		if (!record.compare("enter")) {
			it = m.find(name);
			if (it != m.end()) {
				it->second = true;
			}
			else {
				m.insert({ name, true });
			}
		}
		else {
			it = m.find(name);
			if (it != m.end()) {
				it->second = false;
			}
			else {
				m.insert({ name, false });
			}
		}
	}

	it = m.end();
	while (it-- != m.begin()) {
		if (it->second)
			cout << it->first << "\n";
	}

	return 0;
}