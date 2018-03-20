#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>
using namespace std;

int N;
int W[12][12] = { 0, };
int visit[11] = { 0, };
int MIN = INT_MAX;
stack<pair<int, int>> st;

void func(int v[], stack<pair<int, int>> s);

int main() {
	cin >> N;

	for (int i = 0; i < N*N; i++) {
		cin >> W[i / N][i % N];
	}

	st.push({ 0,0 });
	visit[0] = 1;

	func(visit, st);

	cout << MIN << endl;

	return 0;
}

void func(int v[], stack<pair<int, int>> s) {
	if (s.size() == N) {
		int end = s.top().second + W[s.top().first][0];

		if (MIN > end)
			MIN = end;
		
		return;
	}

	if (MIN < s.top().second)
		return;

	for (int i = 0; i < N; i++) {
		if (v[i] == 1) {
			continue;
		}

		int now = s.top().first;
		int val = s.top().second + W[now][i];


		if (W[now][i] == 0)
			continue;

		s.push({ i,val });
		v[i] = 1;

		func(v, s);

		s.pop();
		v[i] = 0;
	}
}