#include <iostream>
using namespace std;

int N;
int A[1000001] = { 0, };
int B, C;
long long cnt = 0;

int main() {
	//cin >> N;
	scanf("%d", &N);

	for (int i = 0 ;i < N ; i++) {
		//cin >> A[i];
		scanf("%d", &A[i]);
	}

	//cin >> B >> C;
	scanf("%d%d", &B, &C);

	for (int i = 0; i < N; i++) {
		if (A[i] - B <= 0) {
			cnt++;
		}
		else if ((A[i] - B) % C == 0) {
			cnt = ((A[i] - B) / C) + cnt + 1;
		}
		else {
			cnt = ((A[i] - B) / C) + cnt + 2;
		}
	}

	//cout << cnt << endl;
	printf("%lld\n", cnt);

	return 0;
}