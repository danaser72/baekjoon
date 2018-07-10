#include <iostream>
using namespace std;

int N, F;
int ans = -1;

int main() {
	cin >> N >> F;

	N /= 100;
	N *= 100;

	while ((N + ++ans) % F);

	if (ans < 10)
		cout << "0";
	cout << ans << endl;


	return 0;
}