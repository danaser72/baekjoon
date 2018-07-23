#include <iostream>
using namespace std;

int main() {

	char ch = 0;
	int v[] = { 0,0,0,0 };
	while (ch != EOF) {
		ch = getchar();

		if (ch >= 'a' && ch <= 'z') {
			v[0]++;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			v[1]++;
		}
		else if (ch >= '0' && ch <= '9') {
			v[2]++;
		}
		else if (ch == ' ') {
			v[3]++;
		}

		if (ch == '\n') {
			for (int i = 0; i < 4; i++) {
				cout << v[i] << " ";
				v[i] = 0;
			}
			cout << endl;
		}
	}

	return 0;
}