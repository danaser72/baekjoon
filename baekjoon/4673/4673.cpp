#include <iostream>
using namespace std;

#define MAX 10000
int arr[MAX];

void check(int i);

int main() {
	for (int i = 0; i < MAX; i++)
		arr[i] = i + 1;

	for (int i = 1; i <= MAX; i++) {
		if(arr[i - 1] == i)
			check(i);
	}

	for (int i = 0; i < MAX; i++) {
		if (arr[i] != 0)
			cout << i + 1 << endl;
	}

	return 0;
}

void check(int i) {
	int sum = i + (i / 10000) +
		(i % 10000) / 1000 + 
		(i % 1000) / 100 + 
		(i % 100) / 10 + 
		(i % 10);

	if (sum > 10000 || arr[sum - 1] == 0)
		return;
	arr[sum - 1] = 0;

	check(sum);
}