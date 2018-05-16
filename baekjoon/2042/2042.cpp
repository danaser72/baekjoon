#include <vector>
#include <iostream>
using namespace std;

int N, M, K;
long long tree[2100000] = { 0, };
long long a[1000002];

long long init(long long a[], int node, int start, int end);
void update(int node, int start, int end, int index, long long diff);
long long print(int node, int start, int end, int left, int right);

int main() {
	//cin >> N >> M >> K;
	scanf("%d%d%d", &N, &M, &K);

	long long t;
	for (int i = 0; i < N; i++) {
		//cin >> t;
		scanf("%lld", &t);
		a[i] = t;
	}

	init(a, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int m, k;
		//cin >> t;
		scanf("%d", &k);

		//cin >> m >> n;
		scanf("%d", &m);

		if (k == 1) {
			long long n;
			scanf("%lld", &n);
			long long diff = n - a[m - 1];
			a[m - 1] = n;
			update(1, 0, N - 1, m - 1, diff);
		}
		else if (k == 2) {
			int n;
			scanf("%d", &n);
			printf("%lld\n", print(1, 0, N - 1, m - 1, n - 1));
		}
	}
	return 0;
}

long long init(long long a[], int node, int start, int end) {
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, node * 2, start, (start + end) / 2) + init(a, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;

	tree[node] += diff;

	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long print(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return tree[node];
	else
		return print(node * 2, start, (start + end) / 2, left, right) + print(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}