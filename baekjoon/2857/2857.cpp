#include <iostream>
#include <string>
using namespace std;

string arr[5];

int main() {
	int cnt = 0;

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 5; i++) {
		if (arr[i].find("FBI") <= 10) {
			cnt++;
			cout << i + 1 << " ";
		}
	}
	if (cnt == 0) {
		cout << "HE GOT AWAY!" << endl;
	}
	else {
		cout << endl;
	}


	return 0;
}