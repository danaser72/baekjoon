/*
** ref : https://www.acmicpc.net/blog/view/27
*/

#include <iostream>
using namespace std;

pair<int, int> P[3];
int a1, a2, a3, b1, b2, b3;

int main() {
	int m, n;

	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

	int temp = (a2 - a1)*(b3 - b1) - (b2 - b1) * (a3 - a1);

	if (temp > 0)
		cout << "1" << endl;
	else if (temp == 0)
		cout << "0" << endl;
	else
		cout << "-1" << endl;

	return 0;
}