#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
using namespace std;

int N;
string str;
map<string, int> m;

int main() {
	cin >> N;
	map<string, int>::iterator MAX;

	while (N--) {
		cin >> str;

		map<string, int>::iterator it = m.find(str);

		if (it != m.end()) {
			it->second++;
		}
		else {
			m[str] = 0;
		}
		
		MAX = m.begin();

		for (it = m.begin(); it != m.end(); it++) {
			if (MAX->second < it->second) {
				MAX = it;
			}
		}
	}

	cout << MAX->first << endl;
	return 0;
}