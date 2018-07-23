#include <iostream>
using namespace std;

int X;
int stick[] = { 1,2,4,8,16,32,64 };

int main() {
	cin >> X;
	
	int t = 0;
	int cnt = 0;

	while (X != t) {
		cnt++;

		for (int i = 6; i >= 0; i--) {
			if (t + stick[i] <= X) {
				t += stick[i];
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}