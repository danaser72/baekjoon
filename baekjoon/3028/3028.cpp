#include <iostream>
#include <string>
using namespace std;

int arr[3] = { 1,0,0 };
string str;

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A') {
			int t = arr[0];
			arr[0] = arr[1];
			arr[1] = t;
		}
		else if (str[i] == 'B') {
			int t = arr[2];
			arr[2] = arr[1];
			arr[1] = t;
		}
		else {
			int t = arr[0];
			arr[0] = arr[2];
			arr[2] = t;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] == 1) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}