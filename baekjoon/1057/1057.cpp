#include <iostream>
#include <vector>
using namespace std;

int N;
int rem;
int Round = 1;
int x, y;
bool chk = true;

int main() {
	cin >> N >> x >> y;

	while (1) {
		if ((x + 1) / 2 != (y + 1) / 2) {
			Round++;
			x = (x + 1) / 2;
			y = (y + 1) / 2;
		}
		else {
			break;
		}
	}

	cout << Round << endl;

	return 0;
}