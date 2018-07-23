#include <iostream>
#include <string>
#include <map>
using namespace std;

string str;
map<string, int> m;
map<string, int> m2;

int main() {
	m["black"] = 0;
	m["brown"] = 1;
	m["red"] = 2;
	m["orange"] = 3;
	m["yellow"] = 4;
	m["green"] = 5;
	m["blue"] = 6;
	m["violet"] = 7;
	m["grey"] = 8;
	m["white"] = 9;

	m2["black"] = 1;
	m2["brown"] = 10;
	m2["red"] = 100;
	m2["orange"] = 1000;
	m2["yellow"] = 10000;
	m2["green"] = 100000;
	m2["blue"] = 1000000;
	m2["violet"] = 10000000;
	m2["grey"] = 100000000;
	m2["white"] = 1000000000;

	long long sum = 0;
	map<string, int>::iterator it;
	int t = 10;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		if (i != 2) {
			it = m.find(str);
			sum += (t * it->second);
			t /= 10;
		}
		else {
			it = m2.find(str);
			sum *= it->second;
		}
	}

	cout << sum << endl;

	return 0;
}