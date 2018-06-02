/*
** reference : http://codersbrunch.blogspot.com/2017/02/2533-sns.html
*/

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[1000002];
int mark[1000002] = { 0, };
int ans = 0;

void func(int now, int pre);

int main() {
	//cin >> N;
	scanf("%d", &N);

	int u, v;
	for (int i = 1; i < N; i++) {
		//cin >> u >> v;
		scanf("%d%d", &u, &v);

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	func(1, 0);

	//cout << ans << endl;
	printf("%d\n", ans);

	return 0;
}

void func(int now, int pre) {
	int flag = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		if (tree[now][i] != pre) {
			func(tree[now][i], now);

			if (!flag)
				flag = !mark[tree[now][i]];
		}
	}

	if (flag) {
		mark[now] = 1;
		ans++;
	}
}