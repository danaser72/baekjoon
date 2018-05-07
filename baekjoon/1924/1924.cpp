#include <iostream>
using namespace std;

int main() {
	int x, y;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char date[7][4] = {"MON", "TUE", "WEN", "THU", "FRI", "SAT", "SUN"};
	int day;

	cin >> x >> y;

	day = y - 1;

	for (int i = 0; i < x - 1; i++) {
		day += month[i];
	}

	day %= 7;

	cout << date[day] << endl;

	return 0;
}