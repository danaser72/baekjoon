#include <iostream>
#include <string>
using namespace std;

string word;
int arr[28] = { 0, };
int cnt = 0;
bool chk = true;

int main() {
	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		arr[word[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 != 0) {
			cnt++;
		}
		if (cnt >= 2) {
			chk = false;
			break;
		}
	}

	if (!chk) {
		cout << "I'm Sorry Hansoo" << endl;
	}
	else {
		string par = "";
		int pos = 0;
		int odd = -1;

		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 != 0) {
				odd = i;

				for (int j = 0; j < arr[i] - 1; j++) {
					par.insert(par.begin() + pos, 'A' + i);
				}
				pos += arr[i] / 2;
			}
			else {
				for (int j = 0; j < arr[i]; j++) {
					par.insert(par.begin() + pos, 'A' + i);
				}
				pos += arr[i] / 2;
			}
		}
		if (odd != -1)
			par.insert(par.begin() + pos, 'A' + odd);

		cout << par << endl;
	}

	return 0;
}