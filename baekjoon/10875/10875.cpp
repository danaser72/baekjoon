#include <iostream>
#include <vector>
using namespace std;

// type : 0 - x / 1 - y

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

struct xy {
	int type;
	int val;
	int range1;
	int range2;
};

int L, N;
int t;
long long cnt = 0;
int rot = RIGHT;
char dir;

int main() {
	//cin >> L >> N;
	scanf("%d%d", &L, &N);

	int x = 0, y = 0;
	bool chk = false;
	int temp = 987654321;

	vector<xy> v(0);
	for (int i = 0; i < N; i++) {
		//cin >> t >> dir;
		scanf("%d %c", &t, &dir);

		if (rot == RIGHT) {
			x += t;
		}
		else if (rot == DOWN) {
			y -= t;
		}
		else if (rot == LEFT) {
			x -= t;
		}
		else if (rot == UP) {
			y += t;
		}

		for (int j = 0; j < v.size() - 1 && v.size() != 0; j++) {
			if (rot == RIGHT) {
				if (v[j].type == 0) {
					if ((x - t <= v[j].val) && (x >= v[j].val) && (v[j].range1 <= y) && (v[j].range2 >= y)) {
						chk = true;
						int temp2 = v[j].val - (x - t);
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
				else if (v[j].type == 1) {
					if (v[j].val == y && (x - t <= v[j].range1 && x >= v[j].range1)) {
						chk = true;
						int temp2 = v[j].range1 - (x - t);
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
			}
			else if (rot == DOWN) {
				if (v[j].type == 1) {
					if ((y <= v[j].val) && (y + t >= v[j].val) && (v[j].range1 <= x) && (v[j].range2 >= x)) {
						chk = true;
						int temp2 = (y + t) - v[j].val;
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
				else if (v[j].type == 0) {
					if (v[j].val == x && (y + t >= v[j].range2 && y <= v[j].range2)) {
						chk = true;
						int temp2 = y + t - v[j].range2;
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
			}
			else if (rot == LEFT) {
				if (v[j].type == 0) {
					if ((x <= v[j].val) && (x + t >= v[j].val) && (v[j].range1 <= y) && (v[j].range2 >= y)) {
						chk = true;
						int temp2 = (x + t) - v[j].val;
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
				else if (v[j].type == 1) {
					if (v[j].val == y && (x <= v[j].range2 && x + t >= v[j].range2)) {
						chk = true;
						int temp2 = x + t - v[j].range2;
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
			}
			else if (rot == UP) {
				if (v[j].type == 1) {
					if ((y - t <= v[j].val) && (y >= v[j].val) && (v[j].range1 <= x) && (v[j].range2 >= x)) {
						chk = true;
						int temp2 = (y - t) - v[j].val;
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
				else if (v[j].type == 0) {
					if (v[j].val == x && (y >= v[j].range1 && y - t <= v[j].range1)) {
						chk = true;
						int temp2 = v[j].range1 - (y - t);
						if (temp2 < 0)
							temp2 = -temp2;
						temp = temp2 < temp ? temp2 : temp;
					}
				}
			}
		}

		if (chk) {
			cnt += temp;
			//cout << cnt << endl;
			printf("%lld\n", cnt);

			return 0;
		}

		if (x > L || x < -L || y > L || y < -L) {
			if (rot == RIGHT) {
				cnt += (L - (x - t)) + 1;
			}
			else if (rot == DOWN) {
				cnt += (L + (y + t)) + 1;
			}
			else if (rot == LEFT) {
				cnt += (L + (x + t)) + 1;
			}
			else if (rot == UP) {
				cnt += (L - (y - t)) + 1;
			}
			//cout << cnt << endl;
			printf("%lld\n", cnt);
			
			return 0;
		}

		xy newXY;

		if (rot == RIGHT) {
			newXY.type = 1;
			newXY.val = y;
			newXY.range1 = x - t;
			newXY.range2 = x;
		}
		else if (rot == DOWN) {
			newXY.type = 0;
			newXY.val = x;
			newXY.range1 = y;
			newXY.range2 = y + t;
		}
		else if (rot == LEFT) {
			newXY.type = 1;
			newXY.val = y;
			newXY.range1 = x;
			newXY.range2 = x + t;
		}
		else if (rot == UP) {
			newXY.type = 0;
			newXY.val = x;
			newXY.range1 = y - t;
			newXY.range2 = y;
		}

		v.push_back(newXY);
		cnt += t;

		if (dir == 'L') {
			rot = (rot + 3) % 4;

			if (rot == 0)
				rot = 4;
		}
		else if (dir == 'R') {
			rot = rot % 4 + 1;
		}
	}

	t = 200000005;

	if (rot == RIGHT) {
		x += t;
	}
	else if (rot == DOWN) {
		y -= t;
	}
	else if (rot == LEFT) {
		x -= t;
	}
	else if (rot == UP) {
		y += t;
	}

	for (int j = 0; j < v.size() - 1 && v.size() != 0; j++) {
		if (rot == RIGHT) {
			if (v[j].type == 0) {
				if ((x - t <= v[j].val) && (x >= v[j].val) && (v[j].range1 <= y) && (v[j].range2 >= y)) {
					chk = true;
					int temp2 = v[j].val - (x - t);
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
			else if (v[j].type == 1) {
				if (v[j].val == y && (x - t <= v[j].range1 && x >= v[j].range1)) {
					chk = true;
					int temp2 = v[j].range1 - (x - t);
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
		}
		else if (rot == DOWN) {
			if (v[j].type == 1) {
				if ((y <= v[j].val) && (y + t >= v[j].val) && (v[j].range1 <= x) && (v[j].range2 >= x)) {
					chk = true;
					int temp2 = (y + t) - v[j].val;
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
			else if (v[j].type == 0) {
				if (v[j].val == x && (y + t >= v[j].range2 && y <= v[j].range2)) {
					chk = true;
					int temp2 = y + t - v[j].range2;
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
		}
		else if (rot == LEFT) {
			if (v[j].type == 0) {
				if ((x <= v[j].val) && (x + t >= v[j].val) && (v[j].range1 <= y) && (v[j].range2 >= y)) {
					chk = true;
					int temp2 = (x + t) - v[j].val;
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
			else if (v[j].type == 1) {
				if (v[j].val == y && (x <= v[j].range2 && x + t >= v[j].range2)) {
					chk = true;
					int temp2 = x + t - v[j].range2;
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
		}
		else if (rot == UP) {
			if (v[j].type == 1) {
				if ((y - t <= v[j].val) && (y >= v[j].val) && (v[j].range1 <= x) && (v[j].range2 >= x)) {
					chk = true;
					int temp2 = (y - t) - v[j].val;
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
			else if (v[j].type == 0) {
				if (v[j].val == x && (y >= v[j].range1 && y - t <= v[j].range1)) {
					chk = true;
					int temp2 = v[j].range1 - (y - t);
					if (temp2 < 0)
						temp2 = -temp2;
					temp = temp2 < temp ? temp2 : temp;
				}
			}
		}
	}

	if (chk) {
		cnt += temp;
		//cout << cnt << endl;
		printf("%lld\n", cnt);

		return 0;
	}

	if (x > L || x < -L || y > L || y < -L) {
		if (rot == RIGHT) {
			cnt += (L - (x - t)) + 1;
		}
		else if (rot == DOWN) {
			cnt += (L + (y + t)) + 1;
		}
		else if (rot == LEFT) {
			cnt += (L + (x + t)) + 1;
		}
		else if (rot == UP) {
			cnt += (L - (y - t)) + 1;
		}
		//cout << cnt << endl;
		printf("%lld\n", cnt);

		return 0;
	}

	return 0;
}