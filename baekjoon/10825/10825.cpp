#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct profile {
	char name[13];
	int score[3];
};

bool cmp(profile a, profile b) {
	if (a.score[0] == b.score[0]) {
		if (a.score[1] == b.score[1]) {
			if (a.score[2] == b.score[2]) {
				if (strcmp(a.name, b.name) <= 0)
					return true;
				else
					return false;
			}
			return a.score[2] > b.score[2];
		}
		return a.score[1] < b.score[1];
	}
	return a.score[0] > b.score[0];
}

vector<profile> v;

int N;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		profile newPro;
		//cin >> newPro.name >> newPro.score[0] >> newPro.score[1] >> newPro.score[2];
		scanf(" %s %d%d%d", &newPro.name, &newPro.score[0], &newPro.score[1], &newPro.score[2]);

		v.push_back(newPro);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		printf("%s\n", v[i].name);
	}

	return 0;
}