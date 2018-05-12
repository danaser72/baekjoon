/*
** reference https://www.acmicpc.net/board/view/11630
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int N;
long n[102];
vector<int> M;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	sort(n, n + N);

	int _find = n[N - 1] - n[0];
	M.push_back(_find);

	for (int i = 2; i <= sqrt(_find); i++) {
		if (_find % i == 0) {
			vector<int>::iterator iter;
			iter = find(M.begin(), M.end(), i);
			if (iter != M.end()) {
				continue;
			}
			else {
				M.push_back(i);
			}

			iter = find(M.begin(), M.end(), _find / i);
			if (iter != M.end()) {
				continue;
			}
			else {
				M.push_back(_find / i);
			}
		}
	}

	int pos = 0;
	int rem;
	bool chk;
	
	while (pos < M.size()) {
		chk = false;
		rem = n[0] % M[pos];

		for (int i = 1; i < N - 1; i++) {
			if (n[i] % M[pos] != rem) {
				chk = true;
				break;
			}
		}
		
		if (chk)
			M.erase(M.begin() + pos);
		else {
			pos++;
		}
	}

	sort(M.begin(), M.end());

	for (int i = 0; i < M.size(); i++) {
		printf("%d ", M[i]);
	}

	return 0;
}