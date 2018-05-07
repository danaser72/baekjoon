#include <iostream>
#include <string.h>
using namespace std;

char num[36];
long long N;
int B;
char rslt[33] = { 0, };
int len = 0;

void fn(long long Ns);

int main() {
	for (int i = 0; i < 10; i++) {
		num[i] = '0' + i;
	}

	for (int i = 0; i < 26; i++) {
		num[i + 10] = 'A' + i;
	}

	cin >> N >> B;

	fn(N);

	for (int i = len - 1; i >= 0; i--) {
		cout << num[rslt[i]];
	}
	cout << endl;

	return 0;
}

void fn(long long Ns) {
	if (Ns == 0)
		return;

	rslt[len++] = Ns % B;
	fn(Ns/B);
}