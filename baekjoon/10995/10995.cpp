#include <iostream>
using namespace std;

int main() {
	int N;

	//cin >> N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				//cout << "* ";
				printf("* ");
			}
		}
		else {
			for (int j = 0; j < N; j++) {
				//cout << " *";
				printf(" *");
			}
		}
		//cout << endl;
		printf("\n");
	}

	return 0;
}