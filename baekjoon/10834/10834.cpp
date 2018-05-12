#include <iostream>
#include <vector>
using namespace std;

int M;
int a, b, s;
int rot = 1, rot_s = 0;

int main() {
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> s;

		rot = (rot / a) * b;

		rot_s ^= s;
	}

	cout << rot_s << " " << rot << endl;

	return 0;
}