#include <iostream>
#include <string>
using namespace std;

string n = "";
int N, M;

int main() {
	cin >> N >> M;

	n = to_string(N);

	if (n.size() * N < M) {
		for (int i = 0; i < N; i++)
			printf("%d", N);
	}
	else
		for (int i = 0; i < M; i++)
			printf("%c", n[i % n.size()]);

	printf("\n");

	return 0;
}