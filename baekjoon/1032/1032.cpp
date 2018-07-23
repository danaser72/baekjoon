#include <iostream>
#include <string>
using namespace std;

int N;
string str;
string ans = "";

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (i == 0) {
			ans = str;
		}
		else {
			for (int j = 0; j < str.size(); j++) {
				if (str[j] != ans[j]) {
					ans[j] = '?';
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}