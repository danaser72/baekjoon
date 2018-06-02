#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
	int name;
	int rank;
};

int N, M;
int from, to;
vector<int> family[102];
int visit[102] = { 0, };
int ans = -1;

int main() {
	//cin >> N >> from >> to >> M;
	scanf("%d%d%d%d", &N, &from, &to, &M);

	int x, y;
	for (int i = 0; i < M; i++) {
		//cin >> x >> y;
		scanf("%d%d", &x, &y);

		family[x].push_back(y);
		family[y].push_back(x);
	}

	queue<node> q;
	node newNode;
	newNode.name = from;
	newNode.rank = 0;
	q.push(newNode);
	visit[from] = 1;

	while (!q.empty()) {
		int now = q.front().name;
		int r = q.front().rank;
		q.pop();

		if (now == to) {
			ans = r;
			break;
		}
		r++;

		visit[now] = 1;
		for (int i = 0; i < family[now].size(); i++) {
			if (!visit[family[now][i]]) {
				newNode.name = family[now][i];
				newNode.rank = r;
				q.push(newNode);
			}
		}
	}

	//cout << ans << endl;
	printf("%d\n", ans);

	return 0;
}