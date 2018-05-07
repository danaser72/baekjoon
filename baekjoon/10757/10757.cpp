#include <iostream>
#include <string.h>
using namespace std;

char arr1[10010];
char arr2[10010];
char arr3[10010];

int main() {
	cin >> arr1 >> arr2;
	int size1 = strlen(arr1);
	int size2 = strlen(arr2);

	int i = size1, j = size2;
	int ind = 0;
	int carrys = 0;

	while (1) {
		arr3[ind] = carrys + '0';

		if (!i && !j) {
			break;
		}

		int a, b;

		if (i == 0) {
			a = 0;
		}
		else {
			a = arr1[--i] - '0';
		}

		if (j == 0) {
			b = 0;
		}
		else {
			b = arr2[--j] - '0';
		}

		if (a + b + arr3[ind] - '0' >= 10) {
			arr3[ind] = (arr3[ind] + a + b - '0') % 10 + '0';
			ind++;
			carrys = 1;
		}
		else {
			arr3[ind++] += a + b;
			carrys = 0;
		}
	}
	if (arr3[ind] == '0') {
		ind--;
	}

	for (int i = ind; i >= 0; i--) {
		cout << (char)arr3[i];
	}

	return 0;
}