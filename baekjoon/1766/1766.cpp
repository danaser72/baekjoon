/*
** reference http://joonas-yoon.blogspot.kr/2016/05/1766.html
*/

#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> li;
vector<int> v[32002];
priority_queue<int, vector<int>, greater<int>> pq;
int approach[32002] = { 0, };

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		v[x - 1].push_back(y - 1);
		approach[y - 1]++;
	}


	for (int i = 0; i < N; i++) {
		if (approach[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		int i = pq.top();
		li.push_back(i);
		pq.pop();
		
		for (int j = 0; j < v[i].size(); j++) {
			approach[v[i][j]] --;

			if (approach[v[i][j]] == 0) {
				pq.push(v[i][j]);
			}
		}
	}
	

	for (int i = 0; i < li.size(); i++) {
		cout << li[i] + 1 << " ";
	}

	return 0;
}