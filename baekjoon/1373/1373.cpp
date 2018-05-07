#include <iostream>
#include <string.h>
using namespace std;

char val[1000002];
char trans[333336] = { 0, };
int indx = 0;

int main() {
	cin >> val;
	int i;
	for (i = strlen(val) - 1; i >= 2; i = i - 3) {
		trans[indx++] = (val[i] - '0') + (val[i - 1] - '0') * 2 + (val[i - 2] - '0') * 4;
	}

	if (i == 0) {
		trans[indx++] = (val[0] - '0');
	}
	else if (i == 1) {
		trans[indx++] = (val[0] - '0') * 2 + (val[1] - '0');
	}

	for (int i = indx - 1; i >= 0; i--) {
		cout << (int)trans[i];
	}
	cout << endl;

	return 0;
}