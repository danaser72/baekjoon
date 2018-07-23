#include <iostream>
#include <vector>
using namespace std;

int N;
bool arr[10002] = { 0, };

int main() {
	cin >> N;
	vector<int> v;

	int t;
	int pos = -1;
		
	for (int i = 0; i < N; i++) {
		cin >> t;
		v.push_back(t);

		if (i == 0)
			continue;

		if (v[i] < v[i - 1])
			pos = i - 1;
	}

	if (pos == -1)
		cout << pos << endl;
	else {
		for (int i = 0; i < pos; i++) {
			arr[v[i]] = true;
		}

		for (int i = v[pos] - 1; i > 0; i--) {
			if (arr[i] == 0) {
				arr[i] = true;
				v[pos] = i;
				break;
			}
		}

		for (int i = pos + 1; i < v.size(); i++) {
			for (int j = N; j > 0; j--) {
				if (arr[j] == 0) {
					arr[j] = true;
					v[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}


	return 0;
}