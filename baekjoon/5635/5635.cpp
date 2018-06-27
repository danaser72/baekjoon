#include <iostream>
#include <string>
using namespace std;

string name[102];
int dd[102];
int mm[102];
int yy[102];

int N;
int old = 0, young = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name[i] >> dd[i] >> mm[i] >> yy[i];
	}

	for (int i = 1; i < N; i++) {
		if (yy[i] < yy[old]) {
			old = i;
		}
		else if (yy[i] == yy[old]) {
			if (mm[i] < mm[old]) {
				old = i;
			}
			else if (mm[i] == mm[old]) {
				if (dd[i] < dd[old]) {
					old = i;
				}
			}
		}

		if (yy[i] > yy[young]) {
			young = i;
		}
		else if (yy[i] == yy[young]) {
			if (mm[i] > mm[young]) {
				young = i;
			}
			else if (mm[i] == mm[young]) {
				if (dd[i] > dd[young]) {
					young = i;
				}
			}
		}
	}

	cout << name[young] << endl << name[old] << endl;

	return 0;
}