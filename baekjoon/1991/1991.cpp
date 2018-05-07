#include <iostream>
using namespace std;

int N;
char arr[27][3] = { 0, };

void front(int cur);
void mid(int cur);
void back(int cur);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		arr[temp - 'A'][0] = temp;
		for (int j = 0; j < 2; j++) {
			cin >> arr[temp - 'A'][j+1];
		}
	}

	front(0);
	cout << endl;
	mid(0);
	cout << endl;
	back(0);
	cout << endl;

	return 0;
}

void front(int cur) {
	if (arr[cur][1] == '.' && arr[cur][2] == '.') {
		cout << arr[cur][0];
		return;
	}

	cout << arr[cur][0];
	if (arr[cur][1] != '.') {
		front(arr[cur][1]-'A');
	}

	if (arr[cur][2] != '.') {
		front(arr[cur][2]-'A');
	}
}

void mid(int cur) {
	if (arr[cur][1] == '.' && arr[cur][2] == '.') {
		cout << arr[cur][0];
		return;
	}

	if (arr[cur][1] != '.') {
		mid(arr[cur][1] - 'A');
	}

	cout << arr[cur][0];

	if (arr[cur][2] != '.') {
		mid(arr[cur][2] - 'A');
	}
}

void back(int cur) {
	if (arr[cur][1] == '.' && arr[cur][2] == '.') {
		cout << arr[cur][0];
		return;
	}

	if (arr[cur][1] != '.') {
		back(arr[cur][1] - 'A');
	}

	if (arr[cur][2] != '.') {
		back(arr[cur][2] - 'A');
	}

	cout << arr[cur][0];
}