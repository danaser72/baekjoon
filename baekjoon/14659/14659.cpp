#include <iostream>
using namespace std;

int N;
int h;
int pre = 0;
int MAX = 0;

int main() {
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> h;

		if (pre < h) {
			pre = h;
			MAX = cnt > MAX ? cnt : MAX;
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	MAX = cnt > MAX ? cnt : MAX;

	cout << MAX << endl;

	return 0;
}