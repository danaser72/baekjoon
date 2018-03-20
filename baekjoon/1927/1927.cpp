#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue< int, vector<int>, greater<int> > q;
int N, x;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (q.size() == 0)
				cout << "0" << endl;
			else {
				cout << q.top() << endl;
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
	return 0;
}

/*
#include <iostream>
#include <limits.h>
using namespace std;

int arr[100003] = { 0, };
int val[100003] = { 0, };

int N;
int x;
int cnt = 0;
int index = 0;
int MIN = INT_MAX - 1;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (cnt == 0) {
				cout << "0" << endl;
			}
			else {
				cout << MIN << endl;
				arr[val[index]] = 0;
				MIN = INT_MAX;
				val[index] = val[cnt - 1];
				val[cnt - 1] = 0;

				for (int j = 0; j < 100003 && val[j] != 0; j++) {
					if (MIN >= arr[val[j]]) {
						MIN = arr[val[j]];
						index = val[j];
					}
				}
				cnt--;
			}
		}
		else {
			for (int j = (x % 100003); ; j++) {
				if (arr[j] == 0) {
					arr[j] = x;
					val[cnt] = j;

					if (x < MIN) {
						MIN = x;
						index = j;
					}
					break;
				}
			}
			cnt++;
		}
	}

	return 0;
}
*/