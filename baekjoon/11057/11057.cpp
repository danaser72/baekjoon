#include <iostream>
#include <string.h>
using namespace std;

#define rem 10007

int N;
long long d[10];
long long sum;

int main() {
	cin >> N;

	for (int i = 0; i < 10; i++)
		d[i] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			sum = 0;
			for (int k = j; k < 10; k++) {
				sum = (sum + d[k]) % rem;
			}
			d[j] = sum;
		}
	}

	cout << d[0] << endl;

	return 0;
}