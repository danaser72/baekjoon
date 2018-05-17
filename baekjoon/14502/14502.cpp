#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<vector<int>> arr;
//int arr[10][10] = { 0, };
int MOVE[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int MAX = 0;

void make_wall(stack<pair<int, int>> st, vector<vector<int>> arr, vector<pair<int, int>>, queue<pair<int, int>>, int start, int safe);
void spread(queue<pair<int, int>>, vector<vector<int>> arr, int safe);

int main() {
	vector<pair<int, int>> safe_zone;
	queue<pair<int, int>> virus_zone;

	int safe = 0;
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vector<int> element(M);
			arr.push_back(element);

			//cin >> arr[i][j];
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				safe_zone.push_back({ i,j });
				safe++;
			}
			else if (arr[i][j] == 2) {
				virus_zone.push({ i,j });
			}
		}
	}

	stack<pair<int, int>> st;
	
	make_wall(st, arr, safe_zone, virus_zone, 0, safe);

	printf("%d\n", MAX);

	return 0;
}

void make_wall(stack<pair<int, int>> st, vector<vector<int>> arr, vector<pair<int, int>> safe_zone, queue<pair<int, int>> virus_zone, int start, int safe) {
	if (st.size() == 3) {
		spread(virus_zone, arr, safe - 3);
	}
	else {
		for (int i = start; i < safe_zone.size(); i++) {
			int x = safe_zone[i].first, y = safe_zone[i].second;
			st.push({ x,y });
			arr[x][y] = 1;
			make_wall(st, arr, safe_zone, virus_zone, i + 1, safe);

			st.pop();
			arr[x][y] = 0;
		}
	}
}

void spread(queue<pair<int, int>> virus_zone, vector<vector<int>> arr, int safe) {
	while (!virus_zone.empty()) {
		int x = virus_zone.front().first;
		int y = virus_zone.front().second;
		virus_zone.pop();

		for (int i = 0; i < 4; i++) {
			int n = x + MOVE[i][0];
			int m = y + MOVE[i][1];

			if (n < N && n >= 0 && m < M && m >= 0) {
				if (arr[n][m] == 0) {
					arr[n][m] = 2;
					virus_zone.push({ n, m });
					safe--;
				}
			}
		}
	}

	if (MAX < safe)
		MAX = safe;
}