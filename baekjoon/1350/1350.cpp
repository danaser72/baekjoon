#include <iostream>
using namespace std;

int N;
long long cnt = 0;
long long S[1000];
long long C;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	cin >> C;

	for (int i = 0; i < N; i++) {
		if (S[i] % C == 0) {
			cnt = cnt + S[i] / C;
		}
		else {
			cnt = cnt + 1 + S[i] / C;
		}
	}

	cout << C * cnt << endl;
	
	return 0;
}