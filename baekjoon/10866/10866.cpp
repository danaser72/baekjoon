#include <iostream>
#include <string>
#include <list>
using namespace std;

int N;
string str;
list<int> li;

int main() {
	cin >> N;

	int num;
	while (N--) {
		cin >> str;

		if (!str.compare("push_front")) {
			cin >> num;
			li.push_front(num);
		}
		else if (!str.compare("push_back")) {
			cin >> num;
			li.push_back(num);
		}
		else if (!str.compare("pop_front")) {
			if (!li.empty()) {
				cout << li.front() << "\n";
				li.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (!str.compare("pop_back")) {
			if (!li.empty()) {
				cout << li.back() << "\n";
				li.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (!str.compare("size")) {
			cout << li.size() << "\n";
		}
		else if (!str.compare("empty")) {
			cout << (li.empty() ? 1 : 0) << "\n";
		}
		else if (!str.compare("front")) {
			if (!li.empty())
				cout << li.front() << "\n";
			else
				cout << "-1\n";
		}
		else if (!str.compare("back")) {
			if (!li.empty())
				cout << li.back() << "\n";
			else
				cout << "-1\n";
		}
	}
	
	return 0;
}