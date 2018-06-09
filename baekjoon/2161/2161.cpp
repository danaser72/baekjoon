#include <iostream>
#include <list>
using namespace std;

int N;
list<int> li;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		li.push_back(i);
	}

	while (1) {
		cout << li.front() << " ";

		li.pop_front();
		if (li.size() == 0)
			break;
		li.push_back(li.front());
		li.pop_front();
	}

	cout << endl;

	return 0;
}