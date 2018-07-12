//#include <iostream>
//#include <string>
//using namespace std;
//
//// type
//// none : 0
//// 100	: 1
//// 1	: 2
//// 01	: 3
//
//int T;
//bool chk = false;
//string str;
//
//void func(int pos, int type) {
//	if (pos == str.size() && type == 0) {
//		chk = true;
//	}
//
//	if (chk)
//		return;
//
//	if (type == 0) {
//		if (str[pos] == '0') {
//			if (str[pos + 1] == '1') {
//				func(pos + 2, 0);
//			}
//		}
//		else if (str[pos] == '1') {
//			if (str[pos + 1] == '0' && str[pos + 2] == '0') {
//				func(pos + 3, 1);
//			}
//		}
//	}
//	else if (type == 1) {
//		if (str[pos] == '0') {
//			func(pos + 1, 1);
//		}
//		else if (str[pos] == '1') {
//			func(pos + 1, 2);
//			func(pos + 1, 0);
//		}
//	}
//	else if (type == 2) {
//		if (str[pos] == '1') {
//			func(pos + 1, 2);
//		}
//		func(pos, 0);
//	}
//}
//
//int main() {
//	cin >> T;
//
//	while (T--) {
//		chk = false;
//		cin >> str;
//
//		func(0, 0);
//
//		if (chk)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

// 9 : fail
int T;
string str;
int state[][2] = { { 5, 1 },{ 2, 9 },{ 3, 9 },{ 3, 4 },{ 5, 7 },{ 9, 6 },{ 5, 1 },{ 8, 7 },{ 3, 6 },{ 9, 9 } };

int main() {
	cin >> T;

	while (T--) {
		cin >> str;

		int ind = 0;
		int pos = 0;
		bool chk = true;

		while (ind != str.size()) {
			pos = state[pos][str[ind++] - '0'];
		}

		if (pos == 4 || pos == 6 || pos == 7)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}