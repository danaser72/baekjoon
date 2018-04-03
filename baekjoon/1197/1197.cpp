#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define KRUSKAL


#ifdef  PRIM
int V, E, A, B, C;
vector<pair<int, int>> W[10002];

int visit[10002] = { 0, };

void func(int start);

int main() {
	scanf("%d%d", &V, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &A, &B, &C);

		W[A].push_back({ B,C });
		W[B].push_back({ A,C });
	}

	func(1);

	return 0;
}

void func(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	visit[start] = 1;
	int wv = 0;

	for (int i = 0; i < W[start].size(); i++) {
		pq.push({ W[start][i].second, W[start][i].first });
	}
	
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (visit[now])
			continue;

		wv += cost;
		visit[now] = 1;

		for (int i = 0; i < W[now].size(); i++) {
			pq.push({ W[now][i].second, W[now][i].first });
		}
	}

	printf("%d\n", wv);
}

#endif

#ifdef KRUSKAL
int V, E, A, B, C;
typedef struct kruskal {
	int from;
	int to;
	int val;
} KS;

vector<KS> W;

int parent[10002] = { 0, };
int level[10002] = { 0, };

int Find(int u);
bool Union(int u, int v);
int wv = 0;
bool cmp(KS a, KS b) {
	return a.val < b.val;
}

int main() {
	scanf("%d%d", &V, &E);

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &A, &B, &C);
		KS newKS;
		newKS.from = A;
		newKS.to = B;
		newKS.val = C;
		W.push_back(newKS);
	}

	sort(W.begin(), W.end(), cmp);

	for (int i = 0; i < E; i++) {
		if (Union(W[i].from, W[i].to))
			wv += W[i].val;
	}

	printf("%d\n", wv);

	return 0;
}

int Find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = Find(parent[u]);
}


bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	// Cycle check
	if (u == v)
		return false;

	parent[u] = v;

	return true;
}

#endif