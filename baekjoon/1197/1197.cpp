#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int V, E, A, B, C;
vector<pair<int, int>> W[10002];
int visit[10002] = { 0, };

void func(int, int);

int main() {
	scanf("%d%d", &V, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &A, &B, &C);

		W[A].push_back({ B,C });
		W[B].push_back({ A,C });
	}
	visit[1] = 1;
	int cnt = 0;
	int wv = 0;

	while (cnt++ != V - 1) {
		int minimum = INT_MAX;
		int minP = -1;

		for (int i = 1; i <= V; i++) {
			if (visit[i] == 1) {
				for (int j = 0; j < W[i].size(); j++) {
					if (!visit[W[i][j].first] && minimum > W[i][j].second) {
						minimum = W[i][j].second;
						minP = W[i][j].first;
					}
				}
			}
		}
		visit[minP] = 1;
		wv += minimum;
	}

	printf("%d\n", wv);

	return 0;
}