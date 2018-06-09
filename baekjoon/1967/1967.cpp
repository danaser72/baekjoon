/*
**	reference : http://koosaga.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84-Diameter-of-tree
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct value {
	int to;
	int edge;
};

struct node {
	vector<value> leaf;
};

node tree[10002];

int N;
int MAX = 0;

int main() {
	cin >> N;

	int from, to, edge;

	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &from, &to, &edge);

		value newVal0, newVal1;
		newVal0.to = to;
		newVal0.edge = edge;

		newVal1.to = from;
		newVal1.edge = edge;

		tree[from].leaf.push_back(newVal0);
		tree[to].leaf.push_back(newVal1);
	}

	// 지름값, 현재 위치, 이전 위치
	queue<pair<int, pair<int, int>>> q;

	int end = 0;
	q.push({ 0, {1, -1} });

	while (!q.empty()) {
		int rad = q.front().first;
		int now = q.front().second.first;
		int before = q.front().second.second;
		q.pop();

		for (int i = 0; i < tree[now].leaf.size(); i++) {
			if (tree[now].leaf[i].to != before) {
				q.push({ rad + tree[now].leaf[i].edge, {tree[now].leaf[i].to, now} });
			}
		}
		if (rad > MAX) {
			MAX = rad;
			end = now;
		}
	}

	q.push({ 0, {end, -1} });

	while (!q.empty()) {
		int rad = q.front().first;
		int now = q.front().second.first;
		int before = q.front().second.second;
		q.pop();

		for (int i = 0; i < tree[now].leaf.size(); i++) {
			if (tree[now].leaf[i].to != before) {
				q.push({ rad + tree[now].leaf[i].edge,{ tree[now].leaf[i].to, now } });
			}
		}
		if (rad > MAX) {
			MAX = rad;
		}
	}

	printf("%d\n", MAX);

	return 0;
}