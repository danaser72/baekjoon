#include <iostream>
using namespace std;

int N, M;
int arr[1001] = { 0, };
int index[1001] = { 0, };

int main() {
	cin >> N >> M;
	
	int k = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			k++;
			k %= N;

			if (arr[k] != 0)
				j--;
		}

		arr[k] = 1;
		index[i] = k + 1;
	}

	cout << "<";
	for (int i = 0; i < N - 1; i++) {
		cout << index[i] << ", ";
	}
	cout << index[N - 1] << ">" << endl;

	return 0;
}