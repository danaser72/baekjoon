#include <iostream>
#include <queue>
using namespace std;

int F, G, S;
int U, D;
int Ucnt = 0, Dcnt = 0;
queue<int> q;

bool check = true;

void fn(int s, int ccnt);

int main() {
	cin >> F >> S >> G >> U >> D;

	if (S < G) {
		if (U) {
			Ucnt = (G - S) / U;
			S = S + U * Ucnt;
		}
	}
	else {
		if (D) {
			Dcnt = (S - G) / D;
			S = S - D * Dcnt;
		}
	}

	while (check) {
		if (S == G) {
			break;
		}

		queue<int> t = q;

		while (!t.empty()) {
			if (t.front() == S) {
				check = false;
				break;
			}
			t.pop();
		}
		if (!check) {
			break;
		}
		q.push(S);

		if (S + U <= G) {
			Ucnt++;
			S += U;
		}
		else if (S - D > 0) {
			Dcnt++;
			S -= D;
		}
		else {
			check = false;
		}
	}

	if (check) {
		cout << Ucnt + Dcnt << endl;
	}
	else {
		cout << "use the stairs" << endl;
	}

	return 0;
}