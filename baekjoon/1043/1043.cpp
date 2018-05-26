#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int know[52] = { 0, };
vector<int> v[52];

int main() {
	queue<int> q;

	//cin >> N >> M >> K;
	scanf("%d%d%d", &N, &M, &K);
	vector<vector<int>> graph(M);

	while(K--) {
		int t;
		//cin >> t;
		scanf("%d", &t);
		know[t] = 1;
		q.push(t);
	}

	for (int i = 0; i < M; i++) {
		int cnt, num;
		vector<int> t;

		//cin >> cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			//cin >> num;
			scanf("%d", &num);
			t.push_back(num);
			graph[i].push_back(num);
		}

		for (int j = 0; j < t.size(); j++) {
			for (int k = j + 1; k < t.size(); k++) {
				v[t[j]].push_back(t[k]);
				v[t[k]].push_back(t[j]);
			}
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < v[num].size(); i++) {
			if (know[v[num][i]] != 1) {
				know[v[num][i]] = 1;
				q.push(v[num][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (know[i] == 1) {
			for (int j = 0; j < graph.size(); j++) {
				for (int k = 0; k < graph[j].size(); k++) {
					if (graph[j][k] == i) {
						graph.erase(graph.begin() + j);
						j--;
						break;
					}
				}
			}
		}
	}

	//cout << graph.size() << endl;
	printf("%d\n", graph.size());

	return 0;
}