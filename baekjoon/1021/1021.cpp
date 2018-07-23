#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> num;
vector<int> v;
int cnt = 0;

void Left() {
	if (v.empty())
		return;

	v.push_back(v[0]);
	v.erase(v.begin());
}

void Right() {
	if (v.empty())
		return;

	v.insert(v.begin(), v[v.size() - 1]);
	v.erase(v.end() - 1);
}

void func(int n) {
	int pos;
	for (pos = 0; pos < v.size(); pos++) {
		if (v[pos] == n) {
			break;
		}
	}

	if (pos <= v.size() - pos) {
		for (int i = 0; i < pos; i++) {
			Left();
			cnt++;
		}
	}
	else {
		for (int i = 0; i < v.size() - pos; i++) {
			Right();
			cnt++;
		}
	}

	v.erase(v.begin());
}

int main() {
	cin >> N >> M;

	int t;
	while (M--) {
		cin >> t;
		num.push_back(t);
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < num.size(); i++) {
		func(num[i]);
	}

	cout << cnt << endl;

	return 0;
}