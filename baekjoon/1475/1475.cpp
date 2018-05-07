#include <iostream>
using namespace std;

int main() {
	char N[7] = { 0, };
	int set = 0;
	int count;
	int six = 0;

	cin >> N;

	for (int i = 0; i < 10; i++) {
		count = 0;
		for (int j = 0; N[j] != '\0'; j++) {
			if (N[j] - '0' == i) {
				count++;

				if (i == 6 || i == 9)
					six++;
			}
		}
		if (i == 6 || i == 9){
			if (set < (six + 1) / 2)
				set = (six + 1) / 2;
		}
		else {
			if (set < count)
				set = count;
		}
	}
	
	cout << set << endl;

	return 0;
}