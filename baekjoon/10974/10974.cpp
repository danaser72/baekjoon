#include <iostream>
using namespace std;

int N;
int visit[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

void fn(int ind);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[0] = i + 1;
			if (visit[0] == j + 1) {
				continue;
			}
			visit[1] = j + 1;
			fn(2);
		}
	}

	return 0;
}

void fn(int ind) {
	if (ind == N) {
		for (int i = 0; i < N; i++) {
			cout << visit[i] << " ";
		}
		cout << endl;

		return;
	}
	bool check = true;
	for (int i = 0; i < N; i++) {
		check = true;
		for (int j = 0; j < ind; j++) {
			if (visit[j] == i + 1) {
				check = false;
				break;
			}
		}
		if (check) {
			visit[ind] = i + 1;
			fn(ind + 1);
			visit[ind] = -1;
		}
	}
}