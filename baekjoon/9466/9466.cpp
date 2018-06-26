#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int T, N;

int choice[100002];
int cycle[100002];
int visit[100002];
int cnt;


void func(int t, int rot, vector<int> v);

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(cycle, 0, sizeof(choice));
		memset(visit, 0, sizeof(choice));
		cnt = 0;

		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			scanf("%d", &choice[i]);

		for (int i = 1; i <= N; i++) {
			vector<int> v;
			func(i, 1, v);
		}

		printf("%d\n", N - cnt);
	}

	return 0;
}

void func(int t, int rot, vector<int> v) {
	if (visit[t]) {
		if (cycle[t] == 0) {
			cnt = cnt + rot - visit[t];
		}
	}
	else {
		visit[t] = rot;
		rot++;
		func(choice[t], rot);
	}
}