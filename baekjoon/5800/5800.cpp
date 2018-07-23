#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int N;
int score;

int main() {
	cin >> K;

	for (int k = 1; k <= K; k++) {
		cin >> N;
		vector<int> v;
		vector<int> gap;
		for (int n = 0; n < N; n++) {
			cin >> score;
			v.push_back(score);
		}

		sort(v.begin(), v.end());

		for (int i = 1; i < N; i++) {
			gap.push_back(v[i] - v[i - 1]);
		}
		sort(gap.begin(), gap.end());

		cout << "Class " << k << endl
			<< "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << gap[gap.size() - 1] << endl;
	}
	return 0;
}