#include <iostream>
#include <string.h>
using namespace std;

char N[5000];
long long cnt = 0;

int main() {
	cin >> N;
	int len = strlen(N);

	for (int i = 0; i < len; i++) {
		if (N[i] == 1) {
			if (N[i + 1] == 0) {
				cnt++;
				i++;
			}
			else {
				cnt += 2;
			}
		}
	}

	return 0;
}