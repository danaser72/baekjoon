#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int maxs = 0;
int arr[9] = { 0, };
int rst[9] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int k;

	if (N % 2 == 0) {
		for (k = 0; k < N / 2; k++) {
			rst[k * 2] = arr[k];
		}

		for (k; k < N; k++) {
			rst[k * 2 - N + 1 + N % 2] = arr[N - k + N / 2 - 1];
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = i; j < i + N - 1; j++) {
				sum += abs(rst[j%N] - rst[(j + 1) % N]);
			}
			if (maxs < sum) {
				maxs = sum;
			}
		}
	}
	else {
		int sum1 = 0, sum2 = 0;

		for (k = 0; k < N / 2 - 1; k++) {
			rst[k * 2 + 2] = arr[k];
		}
		rst[0] = arr[k++];
		rst[N - 1] = arr[k++];
		for (k; k < N; k++) {
			rst[k * 2 - N] = arr[N - k + N / 2];
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = i; j < i + N - 1; j++) {
				sum += abs(rst[j%N] - rst[(j + 1) % N]);
			}
			if (sum1 < sum) {
				sum1 = sum;
			}
		}

		for (k = 0; k < N / 2; k++) {
			rst[k * 2 + 1] = arr[k];
		}
		
		rst[N - 1] = arr[k++];
		rst[0] = arr[k ++];
		 
		for (k; k < N; k++) {
			rst[k * 2 - N - 1] = arr[N - k + N / 2 + 1];
		}


		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = i; j < i + N - 1; j++) {
				sum += abs(rst[j%N] - rst[(j + 1) % N]);
			}
			if (sum2 < sum) {
				sum2 = sum;
			}
		}

		maxs = sum1 > sum2 ? sum1 : sum2;
	}
	cout << maxs << endl;

	return 0;
}
//
// - n이 홀수 -
// m = (n - 1) / 2
// 작은 것 m개 a1<a2< ... < am
// 큰 것 m개 b1>b2> ... > bm
// 중앙값 c가 있다고 하자.
//
// 다음 두 배치 중 최댓값을 출력하면 된다.
//
// am b1 a1 b2 a2 ...... bm-1 am-1 bm c
// bm a1 b1 a2 b2 ...... am-1 bm-1 am c