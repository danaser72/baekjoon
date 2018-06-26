#include <iostream>
#include <vector>
using namespace std;

int T;
int num;

int main() {
	cin >> T;

	while (T--) {
		vector<int> v;
		cin >> num;

		for (int i = 0; num; i++) {
			if (num % 2 == 1)
				v.push_back(i);
			num /= 2;
		}

		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
	}

	return 0;
}