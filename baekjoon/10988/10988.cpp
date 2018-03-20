#include <iostream>
#include <string.h>
using namespace std;

char word[102];

int check();

int main() {
	cin >> word;

	cout << check() << endl;

	return 0;
}

int check() {
	int ret = 1;
	int iter = strlen(word) / 2 - 1;
	int mid = strlen(word) - 1;


	while (iter >= 0) {
		if (word[iter] != word[mid - iter]) {
			ret = 0;
			break;
		}
		iter--;
	}

	return ret;
}