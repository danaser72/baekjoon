#include <iostream>
#include <math.h>
using namespace std;

int N, W, H;
double diagonal;

int main() {
	int s;
	cin >> N >> W >> H;

	diagonal = sqrt(W * W + H * H);

	while (N--) {
		cin >> s;
		if (diagonal >= s) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}


	return 0;
}