#include <iostream>
using namespace std;

#define MAX 100000
int arr[MAX][2] = { 0, };
int peo[32000] = { 0, };
int person[32000] = { 0, };

int main() {
	int N, M;
	cin >> N >> M;

	int index = 0;

	for (int i = 0; i < M; i++) {
		cin >> arr[i][0] >> arr[i][1];
		peo[arr[i][1] - 1]++;
	}

	for (int i = 0; i < N; i++) {
		if (peo[i] == 0) {
			person[index++] = i + 1;

			for (int j = 0; j < M; j++) {
				if (arr[j][0] == i + 1) {
					peo[arr[j][1] - 1]--;
					arr[j][0] = 0;
					arr[j][1] = 0;
				}
			}
			peo[i] = -1;
			i = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << person[i] << " ";
	}
	cout << endl;





	return 0;
}