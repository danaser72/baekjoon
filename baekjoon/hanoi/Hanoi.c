#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int AA[MAX] = {0}, BB[MAX] = {0}, CC[MAX] = {0};
int cnt = 0;

int Height(int X[], int size);
void Move(int X[], int Y[], int size);
void Hanoi(int A[], int B[], int C[], int n);
void Show(int X[], int size);
void ShowAll();

int Height(int X[], int size) {
    int i;
    for(i = size-1 ; i >= 0 ; i--)
        if(X[i] > 0) {
            return i;
    }

    return -1;
}

void Move(int X[], int Y[], int size) {
    int xH, yH;
 
    xH = Height(X, size);
    yH = Height(Y, size);
 
    if(xH < 0 || (yH >= 0 && X[xH] >= Y[yH])) 
	printf("Error\n");
    Y[yH+1] = X[xH];
    X[xH] = 0;
    cnt++;
}
void Hanoi(int A[], int B[], int C[], int n) {
    if(n == 1) {
        Move(A, B, MAX);
        ShowAll();
    }
    else {
        Hanoi(A, C, B, n-1);
        Move(A, B, MAX);
        ShowAll();
        Hanoi(C, B, A, n-1);
    }

}

void Show(int X[], int size) {
    int i, k, xH;

    xH = Height(X, size);
    for(i = xH ; i >= 0 ; i--) {
        for(k = 0 ; k < X[i] ; k++)
            printf("*");
        printf("\n");
    }
    printf("\n");
}

void ShowAll() {
    system("cls");
    printf("%d th move\n", cnt);
    printf("A----\n");
    Show(AA, MAX);
    printf("\nB----\n");
    Show(BB, MAX);
    printf("\nC----\n");
    Show(CC, MAX);
    system("pause");
}

int main() { 
    int n, i;
    do {
        scanf_s("%d", &n);
    } while (n <= 0 || n > MAX);

    for(i = n-1 ; i >= 0 ; i--)
        AA[i] = n-i;
 
    ShowAll();
    Hanoi(AA, BB, CC, n);
 
    return 0;
}
