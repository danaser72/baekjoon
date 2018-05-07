#include <iostream>
using namespace std;

/*1~99까지는 등차수열 -> 99개*/
#define MAX 1000
int check(int i);
int arr[MAX];

int main() {
	int N;
	int sum = 99;
	cin >> N;

	for (int i = 0; i < MAX; i++)
		arr[i] = i + 1;

	if (N <= 99)
		cout << N << endl;
	else {
		for (int i = 100; i < N + 1; i++) {
			sum += check(i);
		}
		cout << sum << endl;
	}

	return 0;
}

int check(int i) {
	int a = i / 1000;
	int b = (i % 1000) / 100;
	int c = (i % 100) / 10;
	int d = (i % 10);

	int dif1 = a - b;
	int dif2 = b - c;
	int dif3 = c - d;

	if (a != 0) {
		if (dif1 == dif2 && dif2 == dif3)
			return 1;
	}
	else {
		if (dif2 == dif3)
			return 1;
	}

	return 0;
}