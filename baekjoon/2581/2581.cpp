#include <iostream>
#include <vector>
using namespace std;


int M, N;
vector<int> v;
bool arr[10002] = { 0, };

int main() {
	for (int i = 2; i <= 10000; i++) {
		if (!arr[i]) {
			v.push_back(i);

			for (int j = 2; j * i <= 10000; j++) {
				arr[j * i] = true;
			}
		}
	}

	cin >> M >> N;

	int s = -1, e = v.size();

	for (int i = 0; i < v.size(); i++) {
		if (M <= v[i] && v[i] <= N && s == -1) {
			s = i;
		}
		if (N < v[i]) {
			e = i;
			break;
		}
	}

	if (s == -1 || s > e) {
		cout << "-1\n";
	}
	else {
		int sum = 0;

		for (int i = s; i < e; i++) {
			sum += v[i];
		}

		cout << sum << endl << v[s] << endl;
	}

	return 0;
}