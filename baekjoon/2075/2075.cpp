#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		q.push(0);
	}

	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &t);
			q.push(t);
		}
		
		for (int j = 0; j < N; j++) {
			q.pop();
		}
	}

	cout << q.top() << endl;

	return 0;
}