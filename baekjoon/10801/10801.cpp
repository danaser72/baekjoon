#include <iostream>
using namespace std;

int cA[10], cB[10];
int A = 0, B = 0;

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> cA[i];	
	}
	for (int i = 0; i < 10; i++) {
		cin >> cB[i];
	}
	for (int i = 0; i < 10; i++) {
		if (cA[i] < cB[i])
			B++;
		else if (cA[i] > cB[i])
			A++;
	}

	if (A > B)
		cout << "A" << endl;
	else if (A < B)
		cout << "B" << endl;
	else
		cout << "D" << endl;

	return 0;
}