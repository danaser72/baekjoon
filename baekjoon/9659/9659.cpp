#include <iostream>
using namespace std;

int main() {
	long long N;

	//cin >> N;
	scanf("%lld", &N);

	if (N % 2 == 1) {
		//cout << "SK" << endl;
		printf("SK\n");
	}
	else {
		//cout << "CY" << endl;
		printf("CY\n");
	}

	return 0;
}