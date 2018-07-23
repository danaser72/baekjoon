#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

int main() {
	cin >> N;

	vector<int> v;

	string str;
	int t;
	while (N--) {
		cin >> str;

		if (!str.compare("push")) {
			cin >> t;

			v.push_back(t);
		}
		else if (!str.compare("pop")) {
			if (v.empty()) {
				cout << "-1\n";
			}
			else {
				cout << v[0] << endl;
				v.erase(v.begin());
			}
		}
		else if (!str.compare("size")) {
			cout << v.size() << endl;
		}
		else if (!str.compare("empty")) {
			if (v.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (!str.compare("front")) {
			if (v.empty()) {
				cout << "-1\n";
			}
			else {
				cout << v[0] << endl;;
			}
		}
		else if (!str.compare("back")) {
			if (v.empty()) {
				cout << "-1\n";
			}
			else {
				cout << v[v.size() - 1] << endl;
			}
		}
	}

	return 0;
}