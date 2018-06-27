#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt;
vector<int> heavy[102];
vector<int> light[102];

int main() {
	scanf("%d%d", &N, &M);

	int big, small;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &big, &small);
		heavy[big].push_back(small);
		light[small].push_back(big);
	}

	for (int i = 0; i < N; i++) {

	}

	return 0;
}