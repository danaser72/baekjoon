#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

double score[8];
long N;
int ind = 0;
double max1;

int main() {
	cin >> N;

	for (long k = 0; k < N; k++) {
		if (ind < 7) {
			cin >> score[ind++];

			if (ind == 7) {
				sort(score, score + 7);
				max1 = score[6];
			}
		}
		else {
			double temp;
			cin >> temp;

			if (temp < max1) {
				score[6] = temp;
				sort(score, score + 7);
				max1 = score[6];
			}
		}	
	}

	for (int i = 0; i < 7; i++) {
		printf("%.3f\n", score[i]);
	}

	return 0;
}