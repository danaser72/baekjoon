#include <iostream>
#include <stack>
using namespace std;

int N;
int input;
int temp;
stack<pair<int, int>> st;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);

		if (i == 0)
			printf("0 ");
		else {
			if (input < temp) {
				st.push({ i - 1,temp });
				printf("%d ", i);
			}
			else {
				while (!st.empty()) {
					int now = st.top().first;
					int val = st.top().second;

					if (val > input) {
						printf("%d ", st.top().first + 1);
						break;
					}

					st.pop();
				}

				if (st.empty()) {
					printf("0 ");
				}
			}
		}
		temp = input;
	}

	printf("\n");

	return 0;
}