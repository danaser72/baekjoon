#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool chk;
int T;

bool func(string s) {
	if (s.empty() || chk) {
		chk = true;
		return chk;
	}

	bool ret = chk;
	
	for (int i = 0; i < s.size() && !chk; i++) {
		int j;
		for (j = i; j < s.size(); j++) {
			if (s[j] != s[i])
				break;
		}
		if (j - i >= 2)
			ret = func(s.substr(0, i) + s.substr(j));
		i = j - 1;
	}

	return ret;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		string str;
		chk = false;
		cin >> str;

		if (func(str))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	return 0;
}