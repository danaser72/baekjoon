#include <iostream>
using namespace std;

int L, C;
int mo[5] = { 'a','e','i','o','u' };
int arr[27] = { 0, };
int mos_cnt = 0;
char draw[16] = { 0, };

void fn(int cur, int cnt, int mo_cnt);
bool mos_check(int i);

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char t;
		cin >> t;
		arr[t - 'a'] = 1;
	}
	for (int i = 0; i < 27; i++) {
		if (arr[i] == 1) {
			if (mos_check(i)) {
				mos_cnt++;
			}
			draw[0] = i + 'a';
			fn(i + 1, 1, mos_cnt);

			if (mos_check(i)) {
				mos_cnt--;
			}
			draw[0] = 0;
		}
	}

	return 0;
}

void fn(int cur, int cnt, int mo_cnt) {
	if (cnt == L) {
		if (mo_cnt >= 1 && L - mo_cnt >= 2) {
			cout << draw << endl;
		}

		return;
	}

	for (int i = cur; i < 27; i++) {
		if (arr[i] == 1) {
			if (mos_check(i)) {
				mo_cnt++;
			}
			draw[cnt] = i + 'a';
			fn(i + 1, cnt + 1, mo_cnt);

			if (mos_check(i)) {
				mo_cnt--;
			}

			draw[cnt] = 0;
		}
	}
}

bool mos_check(int i) {
	for (int j = 0; j < 5; j++) {
		if (i == mo[j] - 'a') {
			return true;
		}
	}
	return false;
}