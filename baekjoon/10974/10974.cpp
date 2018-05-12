// dfs 방식이지만, 굳이 stack을 사용할 필요가 없다.

#include <iostream>
#include <list>
using namespace std;

int N;
int arr[9] = { 0, };
int visit[9] = { 0, };

void func(int val, int cnt);

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		func(i + 1, 1);
		visit[i] = 0;
	}

	return 0;
}

void func(int val, int cnt) {
	arr[cnt - 1] = val;

	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == 1)
			continue;

		visit[i] = 1;
		func(i + 1, cnt + 1);
		visit[i] = 0;
	}
}


// cout -> printf 로 바꿔보자
//#include <iostream>
//#include <list>
//using namespace std;
//
//int N;
//list<int> _li;
//int visit[9] = { 0, };
//
//void func(list<int> li, int v[], int cnt);
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		_li.push_back(i + 1);
//		visit[i] = 1;
//		func(_li, visit, 1);
//		_li.pop_back();
//		visit[i] = 0;
//	}
//
//	return 0;
//}
//
//void func(list<int> li, int v[], int cnt) {
//	if (cnt == N) {
//		while (!li.empty()) {
//			printf("%d ", li.front());
//			li.pop_front();
//		}
//		printf("\n");
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		if (v[i] == 1)
//			continue;
//
//		li.push_back(i + 1);
//		v[i] = 1;
//		func(li, v, cnt + 1);
//		li.pop_back();
//		v[i] = 0;
//	}
//}
