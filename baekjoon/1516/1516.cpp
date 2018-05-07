#include <iostream>
using namespace std;

int M[500][500];
int same[501];
int index;

int BFS(int k);

int main() {
	int N, data;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int col = 0;
		while (cin >> data) {
			M[i][col++] = data;
			if (data == -1)
				break;
		}
	}

	for (int i = 0; i < 501; i++) {
		same[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		same[i] = BFS(i);
	}

	for (int i = 0; i < N; i++) {
		cout << same[i] << endl;
	}

	return 0;
}

int BFS(int k) {
	int temp;
	if (M[k][1] == -1)
		return M[k][0];
	else {
		for (int i = 1; M[k][i] != -1; i++) {
			temp = M[k][0] + BFS(M[k][i] - 1);
		}
	}
}


/*
void func(int N);

int main() {
	int N, data;
	int time[500];

	cin >> N;

	for (int i = 0; i < N; i++) {
		int col = 0;
		while (cin >> data) {
			M[i][col++] = data;
			if (data == -1)
				break;
		}
	}

	for (int i = 0; i < N; i++)
		time[i] = M[i][0];

	for (int i = 0; i < N; i++) {
		index = 0;
		for (int j = 0; j < 501; j++)
			same[j] = -1;
		func(i);
		for (int j = 0; same[j] != -1; j++)
			time[i] += M[same[j] - 1][0];
	}

	for (int i = 0; i < N; i++) {
		cout << time[i] << endl;
	}

	return 0;
}

void func(int N) {
	bool check;
	if (M[N][1] != -1) {
		for (int i = 1; M[N][i] != -1; i++) {
			func(M[N][i] - 1);
		}
		
		for (int i = 1; M[N][i] != -1; i++) {
			check = true;
			for (int j = 0; j < index + 1; j++) {
				if (same[j] == M[N][i]) {
					check = false;
					break;
				}
				else if (index == 0)
					check = true;
			}
			if (check) {
				same[index++] = M[N][i];
			}
		}
	}
}
*/