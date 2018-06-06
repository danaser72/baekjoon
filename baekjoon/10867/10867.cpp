#include <iostream>
using namespace std;

int N;
int arr[2002] = { 0, };

int main() {
	cin >> N;

	for (int i = 0 ; i < N ; i++) {
		int num;
		scanf("%d", &num);

		arr[num + 1000] = 1;
	}

	for (int i = 0; i < 2002; i++) {
		if (arr[i] == 1)
			printf("%d ", i - 1000);
	}
	printf("\n");

	return 0;
}