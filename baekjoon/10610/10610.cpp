#include <iostream>
#include <vector>
#include <string>
using namespace std;

string N;
vector<int> num(10, 0);
bool ten = false;
bool three = false;

int main() {
	cin >> N;

	long long sum = 0;

	for (int i = 0; i < N.size(); i++) {
		int x = (N[i] - '0') % 10;
		sum += x;
		if (x == 0)
			ten = true;

		num[x]++;
	}

	if (sum % 3 == 0)
		three = true;

	if (ten && three) {
		for (int i = 9; i >= 0; i--) {
			while (num[i]--)
				cout << i;
		}
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}	

	return 0;
}