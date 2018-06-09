#include <iostream>
using namespace std;

int w, h;
int x, y;
int t;
int MOVE[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
int dir = 0;

int main() {
	cin >> w >> h;
	cin >> x >> y >> t;

	while (t--) {
		x += MOVE[dir][0];
		y += MOVE[dir][1];

		if (x == w) {
			if (y == h) {
				dir = 3;
			}
			else if (y == 0) {
				dir = 2;
			}
			else {
				switch (dir) {
				case 0:
					dir = 2;
					break;
				case 1:
					dir = 3;
					break;
				}
			}
		}
		else if (x == 0) {
			if (y == h) {
				dir = 1;
			}
			else if (y == 0) {
				dir = 0;
			}
			else {
				switch (dir) {
				case 2:
					dir = 0;
					break;
				case 3:
					dir = 1;
					break;
				}
			}
		}
		else {
			if (y == h) {
				switch (dir) {
				case 0:
					dir = 1;
					break;
				case 2:
					dir = 3;
					break;
				}
			}
			else if (y == 0) {
				switch (dir) {
				case 1:
					dir = 0;
					break;
				case 3:
					dir = 2;
					break;
				}
			}
		}
	}

	printf("%d %d\n", x, y);

	return 0;
}