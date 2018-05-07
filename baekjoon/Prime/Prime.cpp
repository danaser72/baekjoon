#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100000

int prime[MAX];

void cut(int i);

int main() {
	for (int i = 0; i < MAX; i++) {
		prime[i] = i + 1;
	}

	for (int i = 0; i < MAX; i++) {
		cut(i);
	}

	for (int i = 0; i < MAX; i++) {
		if (prime[i] != 0)
			cout << prime[i] << '\t';
	}

	return 0;
}

void cut(int i) {
	if (i == 0) {
		prime[0] = 0;
		return;
	}

	if (prime[i] != 0) {
		int temp = prime[i];
		for (int j = 2; temp * j <= MAX; j++) {
			prime[temp * j - 1] = 0;
		}
	}
}