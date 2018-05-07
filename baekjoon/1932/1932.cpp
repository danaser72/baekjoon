#include <iostream>
using namespace std;

int arr[501][501];

int tri(int a);

int main() {
	int n;

	cin >> n;


	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1 && j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << tri(n- 1) << endl;

	return 0;
}

int tri(int a) {
	if (a == 0)
		return arr[0][0];
	else {
		for (int i = 0; i < a; i++) {
			arr[a - 1][i] += arr[a][i] >= arr[a][i + 1] ? arr[a][i] : arr[a][i + 1];
		}
		return tri(a - 1);
	}
}