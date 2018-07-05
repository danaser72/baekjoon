/*
** ref : http://ksh-code.tistory.com/134
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 10000011

long long A, B;
long long cnt = 0;
vector<long long> prime;
bool arr[MAX + 1];

int main() {
	cin >> A >> B;
	memset(arr, true, sizeof(arr));

	for (long long i = 2; i < MAX; i++) {
		if (arr[i]) {
			prime.push_back(i);

			for (long long j = 1; j * i <= MAX; j++) {
				arr[i*j] = false;
			}
		}
	}

	for (int i = 0; i < prime.size(); i++) {
		long long p = prime[i];

		while (prime[i] <= B / p) {
			if (prime[i] * p >= A)
				cnt++;
			p *= prime[i];
		}
	}

	cout << cnt << endl;

	return 0;
}