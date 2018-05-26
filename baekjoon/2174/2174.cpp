#include <iostream>
#include <vector>
using namespace std;

// type : 0 - tile / 1 - robot
#define SOUTH	0
#define EAST	1
#define NORTH	2
#define WEST	3

int MOVE[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

struct node {
	int type;
	int num;
	int forward;
	int x;
	int y;
};

int A, B;
int N, M;
int x, y;
char dir;
vector<vector<node>> v;
vector<node> robot;

int main() {
	cin >> B >> A >> N >> M;
	//scanf("%d%d%d%d", &B, &A, &N, &M);

	for (int i = 0; i < A; i++) {
		vector<node> element;

		for (int j = 0; j < B; j++) {
			node newNode;
			newNode.type = 0;
			element.push_back(newNode);
		}
		v.push_back(element);
	}

	for (int i = 0; i < N; i++) {
		cin >> y >> x >> dir;
		//scanf("%d%d %c", &y, &x, &dir);
		
		node newNode;
		newNode.type = 1;
		newNode.num = i + 1;
		newNode.x = x - 1;
		newNode.y = y - 1;

		if (dir == 'N') {
			newNode.forward = NORTH;
		}
		else if (dir == 'E') {
			newNode.forward = EAST;
		}
		else if (dir == 'W') {
			newNode.forward = WEST;
		}
		else if (dir == 'S') {
			newNode.forward = SOUTH;
		}

		v[x - 1][y - 1] = newNode;
		robot.push_back(newNode);
	}

	int what;
	char rot;
	int len;

	for (int i = 0; i < M; i++) {
		cin >> what >> rot >> len;
		//scanf("%d %c %d", &what, &rot, &len);

		what--;

		if (rot == 'F') {
			int m = robot[what].x;
			int n = robot[what].y;
			for (int j = 0; j < len; j++) {
				robot[what].x += MOVE[robot[what].forward][0];
				robot[what].y += MOVE[robot[what].forward][1];

				if (robot[what].x < 0 || robot[what].x > A - 1 || robot[what].y < 0 || robot[what].y > B - 1) {
					cout << "Robot " << what + 1 << " crashes into the wall" << endl;
					//printf("Robot %d crashes into the wall\n", what + 1);
					return 0;
				}

				if (v[robot[what].x][robot[what].y].type == 1) {
					cout << "Robot " << what + 1 << " crashes into robot " << v[robot[what].x][robot[what].y].num << endl;
					//printf("Robot %d crashes into robot %d\n", what + 1, v[robot[what].x][robot[what].y].num);
					return 0;
				}
			}

			v[m][n].type = 0;
			v[robot[what].x][robot[what].y].type = 1;
			v[robot[what].x][robot[what].y].x = robot[what].x;
			v[robot[what].x][robot[what].y].y = robot[what].y;
			v[robot[what].x][robot[what].y].forward = robot[what].forward;
			v[robot[what].x][robot[what].y].num = robot[what].num;
		}
		else if (rot == 'L') {
			robot[what].forward = (robot[what].forward + len) % 4;
			v[robot[what].x][robot[what].y].forward = robot[what].forward;
		}
		else if (rot == 'R') {
			while (len--) {
				robot[what].forward = (robot[what].forward + 3) % 4;
			}
			v[robot[what].x][robot[what].y].forward = robot[what].forward;
		}
	}

	cout << "OK" << endl;
	//printf("OK\n");

	return 0;
}