#include <iostream>
using namespace std;

#define MAX 100000

long long arr[MAX][3] = {0,};

int main() {
	int n;
	int count = 0;
	cin >> n;

	for (int i = 0; i < ; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
		arr[i][2] = arr[i][1] - arr[i][0];
	}

	for (int i = 0; 


	return 0;
}