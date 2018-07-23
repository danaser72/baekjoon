#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T;
int N, M;

int main() {
	cin >> T;

	while (T--) {
		cin >> N >> M;
		
		vector<int> v;
		int cnt = 0;
		int X = 0, Y = 0;
		int len[10];
		int t;

		len[M - 1] = 1;
		for (int i = M - 1; i > 0; i--) {
			len[i - 1] = len[i] * 10;
		}

		for (int i = 0; i < M; i++) {
			cin >> t;
			X += t * len[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> t;
			Y += t * len[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> t;
			v.push_back(t);
		}

		for (int i = 0; i < v.size(); i++) {
			t = 0;
			for (int j = 0; j < M; j++) {
				t += v[(i + j) % N] * len[j];
			}

			if (t <= Y && t >= X)
				cnt++;
		}

		cout << cnt << endl;
	}
	return 0;
}