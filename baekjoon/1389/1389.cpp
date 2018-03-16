#include <iostream>
#include <vector>
using namespace std;

int N, M;
int adj[102][102] = { 0, };
int arr[102] = { 0, };

void func();

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;

		cin >> A >> B;

		adj[A - 1][B - 1] = 1;
		adj[B - 1][A - 1] = 1;
	}
	
	func();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i] += adj[i][j];
		}
	}
	
	int min = arr[0], minPoint = 0;

	for (int i = 0; i < arr[i]; i++) {
		if (min > arr[i]) {
			min = arr[i];
			minPoint = i;
		}
	}
	cout << minPoint + 1 << endl;

	return 0;
}

void func() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (k != i && adj[k][i] >= 1) {
				for (int j = 0; j < N; j++) {
					if (k != j && adj[i][j] >= 1) {
						if (adj[k][j] == 0 || adj[k][j] > adj[k][i] + adj[i][j]) {
							adj[k][j] = adj[k][i] + adj[i][j];
							adj[j][k] = adj[k][j];
						}
					}
				}
			}
		}
	}
}