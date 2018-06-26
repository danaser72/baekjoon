#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
	int upper;
	vector<int> leaf;
};

int N;
node arr[100002];

int main() {
	scanf("%d", &N);

	int from, to;

	for (int i = 1; i < N; i++) {
		scanf("%d%d", &from, &to);

		arr[from].upper = 0;
		arr[to].upper = 0;
		arr[from].leaf.push_back(to);
		arr[to].leaf.push_back(from);
	}

	queue<int> q;
	for (int i = 0; i < arr[1].leaf.size(); i++) {
		arr[arr[1].leaf[i]].upper = 1;
		q.push(arr[1].leaf[i]);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].leaf.size(); i++) {
			if (arr[x].leaf[i] != arr[x].upper) {
				arr[arr[x].leaf[i]].upper = x;
				q.push(arr[x].leaf[i]);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		printf("%d\n", arr[i].upper);
	}

	return 0;
}