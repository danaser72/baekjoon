#include <iostream>
using namespace std;

int N, Q;
int N_time[102];
int Q_t;


int main() {
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> N_time[i];

	for (int i = 0; i < Q; i++) {
		cin >> Q_t;

		int val = 0;
		for (int i = 0; i < N; i++) {
			val += N_time[i];

			if (val - 1 >= Q_t) {
				cout << i + 1 << endl;
				break;
			}
		}
	}

	return 0;
}