#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string str;
vector<string> v;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		int j;
		bool chk = false;

		for (j = 0; j < v.size(); j++) {
			if (v[j].size() > str.size()) {
				break;
			}
			else if (v[j].size() == str.size()) {
				if (v[j].compare(str) > 0) {
					break;
				}
				else if (v[j].compare(str) == 0) {
					chk = true;
				}
			}
		}

		if (!chk)
			v.insert(v.begin() + j, str);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}