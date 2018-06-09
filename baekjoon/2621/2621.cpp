#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define R 0
#define B 1
#define Y 2
#define G 3

int color[4] = { 0, };
vector<int> number;
int numCnt[10] = { 0, };
bool row = false;
bool chk = false;
int ans = 0;

int type;

int main() {
	char clr;
	int num;

	for (int i = 0; i < 5; i++) {
		cin >> clr >> num;

		if (clr == 'R')
			color[R]++;
		else if (clr == 'B')
			color[B]++;
		else if (clr == 'Y')
			color[Y]++;
		else if (clr == 'G')
			color[G]++;

		numCnt[num]++;
		number.push_back(num);
	}
	sort(number.begin(), number.end());

	for (int i = 0; i < 4; i++) {
		if (color[i] == 5) {
			chk = true;
			break;
		}
	}

	for (int i = 1; i <= 5; i++) {
		if (numCnt[i] && numCnt[i + 1] && numCnt[i + 2] && numCnt[i + 3] && numCnt[i + 4]) {
			row = true;
		}
	}

	if (chk) {
		if (row) {
			ans = 900 + number[4];
		}
		else {
			ans = 600 + number[4];
		}
	}

	if (row) {
		ans = ans > 500 + number[4] ? ans : 500 + number[4];
	}

	bool three = false;
	int pos = 0;
	bool two = false;
	for (int i = 1; i <= 9; i++) {
		if (numCnt[i] >= 4) {
			ans = ans > 800 + i ? ans : 800 + i;
		}
		if (numCnt[i] == 3) {
			if (two) {
				ans = ans > 700 + i * 10 + pos ? ans : 700 + i * 10 + pos;
			}
			else {
				three = true;
				pos = i;
				ans = ans > 400 + i ? ans : 400 + i;
			}
		}
		if (numCnt[i] == 2) {
			if (two) {
				ans = ans > 300 + i * 10 + pos ? ans : 300 + i * 10 + pos;
			}

			if (three) {
				ans = ans > 700 + pos * 10 + i ? ans : 700 + pos * 10 + i;
			}
			else {
				two = true;
				pos = i;
				ans = ans > 200 + i ? ans : 200 + i;
			}
		}
	}

	ans = ans > 100 + number[4] ? ans : 100 + number[4];

	cout << ans << endl;

	return 0;
}