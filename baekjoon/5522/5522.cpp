#include <iostream>
using namespace std;


int main() {
	int N;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		//cin >> N;
		scanf("%d", &N);
		sum += N;
	}
	//cout << sum << endl;
	printf("%d\n", sum);

	return 0;
}