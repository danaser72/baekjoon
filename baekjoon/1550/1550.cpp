#include <iostream>
#include <string>
using namespace std;


string str;
int num = 0;

int main() {
	cin >> str;

	int t = 1;

	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] >= 'A' && str[i] <= 'F') {
			num += (str[i] - 'A' + 10) * t;
		}
		else {
			num += (str[i] - '0') * t;
		}

		t *= 16;
	}

	cout << num << endl;

	return 0;
}