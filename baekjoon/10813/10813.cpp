#include <iostream>
using namespace std;

int N, M;
int arr[101];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		arr[i] = i;

	int a, b, t;
	while (M--) {
		cin >> a >> b;
		t = arr[a];
		arr[a] = arr[b];
		arr[b] = t;
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}