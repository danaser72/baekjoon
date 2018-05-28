#include <iostream>
using namespace std;

int N, M;
int arr[102];
int x, y, ball;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> ball;
		for (int j = x; j <= y; j++)
			arr[j] = ball;
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}