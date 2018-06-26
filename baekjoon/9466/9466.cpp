/*
**	ref : http://js1jj2sk3.tistory.com/40
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int T, N;

int arr[100002];
int cycle[100002];
int visit[100002];
int cnt;

int func(int start, int cur, int cnt);

int main() {
	scanf("%d", &T);

	while (T--) {
		cnt = 0;

		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			cycle[i] = 0;
			visit[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			if (visit[i] != 0)
				continue;
			if (visit[arr[i]] == 0) {
				cnt += func(i, i, 1);
			}
		}

		printf("%d\n", N - cnt);
	}

	return 0;
}

int func(int start, int cur, int count) {	
	visit[cur] = count;
	cycle[cur] = start;

	if (visit[arr[cur]]) {
		if (start == cycle[arr[cur]]) {
			return count - visit[arr[cur]] + 1;
		}
		else {
			return 0;
		}
	}
	else {
		return func(start, arr[cur], count + 1);
	}
}