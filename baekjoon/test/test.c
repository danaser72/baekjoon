#include <stdio.h>

void F(int n) {
	if (n / 10 > 0)
		F(n / 10);
	printf("%d", n % 10);
}

int main() {
	F(123);
	printf("\n");

	return 0;
}



//double C(int n, int r);
//
//int main() {
//	int n, r;
//
//	printf("n : ");
//	scanf_s("%d", &n);
//
//	printf("r : ");
//	scanf_s("%d", &r);
//
//	printf("%d C %d : %.2lf", n, r, C(n, r));
//
//	return 0;
//}
//
//double C(int n, int r) {
//	double mom = 1;
//	double son = 1;
//	int i;
//	
//	for (i = n; i >= n - r + 1; i--) {
//		mom *= i;
//	}
//
//	for (i = 1; i <= r; i++) {
//		son *= i;
//	}
//
//	return mom / son;
//}

/*

c���� call by reference �� ����
�׷��� ������ ���� ���� ������ ��, call by pointer�� Ȱ���Ѵ�.

void Start();
int Input();
int Square(int* x);
void Print(int y);

int main() {
int x, y;

Start();
x = Input();
y = Square(&x);
Print(y);
printf("%d\n", x);


return 0;
}

void Start() {
printf("Start\n");
}

int Input() {
int x;
scanf_s("%d", &x);

return x;
}

int Square(int* x) {
(*x)++;

return *x * *x;
}

void Print(int y) {
printf("%d\n", y);
}
*/
