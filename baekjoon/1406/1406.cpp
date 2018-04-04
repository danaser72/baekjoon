#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> li;
int len;
int N;
string str;
list<char>::iterator iter;

int main() {
	char c[3];

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		li.push_back(str[i]);
	}

	iter = li.end();

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", c);

		if (c[0] == 'P') {
			char addText[3];
			scanf("%s", addText);

			li.insert(iter, addText[0]);
		}
		else if (c[0] == 'L') {
			if (iter != li.begin())
				iter--;
		}
		else if (c[0] == 'D') {
			if (iter != li.end())
				iter++;
		}
		else if (c[0] == 'B') {
			if (iter != li.begin()) {
				iter--;
				iter = li.erase(iter);
			}
		}
	}

	for (iter = li.begin(); iter != li.end(); iter++) {
		printf("%c", *iter);
	}
	printf("\n");

	return 0;
}