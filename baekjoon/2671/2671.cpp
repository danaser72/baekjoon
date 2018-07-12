#include <iostream>
#include <string>
using namespace std;

string str;
// 9 : fail
int state[][2] = { { 1,3 },{ 9,2 },{ 1,3 },{ 4,9 },{ 5,9 },{ 5,6 },{ 1,7 },{ 8,7 },{ 5,2 },{ 9,9 } };

int main() {
	cin >> str;

	int ind = 0;
	int pos = 0;

	while (ind != str.size()) {
		pos = state[pos][str[ind++] - '0'];
	}

	if (pos == 2 || pos == 6 || pos == 7)
		cout << "SUBMARINE\n";
	else
		cout << "NOISE\n";

	return 0;
}