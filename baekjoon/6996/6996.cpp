#include <iostream>
#include <string>
using namespace std;

int T;
string A, B;

int main() {
	cin >> T;
	bool chk;

	while (T--) {
		chk = true;
		int alpha[27] = { 0, };
		cin >> A >> B;

		for (int i = 0; i < A.size(); i++) {
			alpha[A[i] - 'a']++;
		}
		for (int i = 0; i < B.size(); i++) {
			alpha[B[i] - 'a']--;
		}

		for (int i = 0; i < 26; i++) {
			if (alpha[i] != 0) {
				chk = false;
				break;
			}
		}

		if (chk) {
			cout << A << " & " << B << " are anagrams." << endl;
		}
		else {
			cout << A << " & " << B << " are NOT anagrams." << endl;
		}
	}

	return 0;
}