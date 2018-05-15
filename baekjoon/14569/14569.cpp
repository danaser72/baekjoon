#include <iostream>
using namespace std;

int N, M;
int t[1001][52];
int s[10001][52];

int main() {
	cin >> N;
	//scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> t[i][0];
		//scanf("%d", &t[i][0]);

		for (int j = 1; j <= t[i][0]; j++) {
			cin >> t[i][j];
			//scanf("%d", &t[i][i]);
		}
	}

	cin >> M;
	//scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		cin >> s[i][0];
		//scanf("%d", &s[i][0]);

		for (int j = 1; j <= s[i][0]; j++) {
			cin >> s[i][j];
			//scanf("%d", &s[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		bool chk = false;
		for (int m = 0; m < N; m++) {
			chk = false;
			for (int n = 1; n <= t[m][0]; n++) {
				bool chk2 = false;
				for (int j = 1; j <= s[i][0]; j++) {
					chk2 = false;
					if (t[m][n] == s[i][j]) {
						chk2 = true;
						break;
					}
				}
				if (!chk2) {
					chk = true;
					break;
				}
			}

			if (!chk) {
				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}