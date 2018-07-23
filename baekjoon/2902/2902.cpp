#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str;
vector<int> v;

int main() {
	cin >> str;

	v.push_back(str[0]);

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '-') {
			v.push_back(str[i + 1]);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << (char)v[i];
	}
	cout << endl;


	return 0;
}