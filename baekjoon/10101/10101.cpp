#include <iostream>
using namespace std;

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);

	if (a == b && b == c && c == 60) {
		printf("Equilateral\n");
	}
	else if (a + b + c == 180) {
		if (a == b || b == c || c == a) {
			printf("Isosceles\n");
		}
		else {
			printf("Scalene\n");
		}
	}
	else {
		printf("Error\n");
	}

	return 0;
}