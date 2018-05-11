#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
pair<int,int> arr[200003];
int ans = 0;
priority_queue<int> pq;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		ans += arr[i].second;

		pq.push(-arr[i].second);

		while (pq.size() > arr[i].first) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;

	return 0;
}