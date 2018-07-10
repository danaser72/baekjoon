#include <iostream>
#include <algorithm>
using namespace std;

int num[4];

int main() {
	for (int i = 0; i < 4; i++)
		cin >> num[i];

	sort(num, num + 4);


	cout << num[0] * num[2] << endl;

	return 0;
}