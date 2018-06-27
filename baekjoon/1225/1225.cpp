#include <iostream>
#include <string>
using namespace std;

string A, B;
long long val = 0;

int main() {
	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			val += (A[i] - '0') * (B[j] - '0');
		}
	}

	cout << val << endl;

	return 0;
}