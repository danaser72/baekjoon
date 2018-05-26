#include <iostream>
#include <string>
using namespace std;

int know[150] = { 0, };
string str[52];
int MAX = 0;
int N, K;

void func(int M, char alpha);

int main() {
	//cin >> N >> K;
	scanf("%d%d", &N, &K);

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		str[i].erase(str[i].begin(), str[i].begin() + 4);
		str[i].pop_back();
		str[i].pop_back();
		str[i].pop_back();
		str[i].pop_back();
	}

	K -= 5;

	know['a'] = 1;
	know['c'] = 1;
	know['i'] = 1;
	know['n'] = 1;
	know['t'] = 1;

	func(K, 'a');

	//cout << MAX << endl;
	printf("%d\n", MAX);

	return 0;
}

void func(int M, char alpha) {
	if (M == 0) {
		int val = 0;

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < str[i].size(); j++) {
				if (know[str[i][j]] == 1)
					cnt++;
				else
					break;
			}
			if (cnt == str[i].size())
				val++;
		}
		if (MAX < val)
			MAX = val;

		return;
	}

	for (int i = alpha; i <= 'z'; i++) {
		if (!know[i]) {
			if (M > 'z' - i + 1)
				continue;

			know[i] = 1;
			func(M - 1, i + 1);
			know[i] = 0;
		}
	}
}