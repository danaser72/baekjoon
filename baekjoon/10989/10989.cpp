#include <iostream>
#include <algorithm>
using namespace std;

int N;
int v[10002] = { 0, };
int MAX = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		v[t]++;

		if (MAX < t) {
			MAX = t;
		}
	}

	for (int i = 1; i <= MAX; i++) {
		while (v[i]--) {
			printf("%d\n", i);
		}
	}

	return 0;
}