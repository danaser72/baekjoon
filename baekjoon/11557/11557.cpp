#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N;
int pos = 0;
string big_name;
long big_drink = 0;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		string name;
		long drink;

		for (int i = 0; i < N; i++) {
			cin >> name >> drink;

			if (big_drink < drink) {
				big_drink = drink;
				big_name = name;
			}
		}

		cout << big_name << endl;
	}

	return 0;
}