#include <stdio.h>

#define SIZE 9

void print(int arr[]);

void bubble(int arr[]);
void selection(int arr[]);
void insertion1(int arr[]);
void insertion2(int arr[]);

int main(){
	int arr1[SIZE] = { 8, 6, 1, 3, 7, 9, 5, 4, 2 };
	int arr2[SIZE] = { 8, 6, 1, 3, 7, 9, 5, 4, 2 };
	int arr3[SIZE] = { 8, 6, 1, 3, 7, 9, 5, 4, 2 };
	int arr4[SIZE] = { 8, 6, 1, 3, 7, 9, 5, 4, 2 };

	bubble(arr1);
	selection(arr2);
	insertion1(arr3);
	insertion2(arr4);

	return 0;
}


void print(int arr[]){
	int i;

	for (i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


// -- Bubble sort --
// i���� 0���� 1�� SIZE ���� ������Ų��.
// j�� 0 ���� SIZE - 1���� ��ȸ�Ѵ�.
// arr[j] >= arr[j + 1] �� ���, �� ���� �ٲ۴�.
void bubble(int arr[]){
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE - 1; j++){
			if (arr[j] >= arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	print(arr);
}


// -- Selection sort --
// i���� 0���� 1�� SIZE - 1 ���� ������Ų��.
// j�� i + 1 ���� SIZE - 1 ���� ��ȸ�ϸ鼭, ���� ���� arr[j] ���� index�� min�� �ִ´�.
// arr[min] ���� arr[i] ���� �ٲ۴�.
void selection(int arr[]){
	int i, j;
	int temp;
	int min;

	for (i = 0; i < SIZE - 1; i++){
		min = i;

		for (j = i + 1; j < SIZE; j++){
			if (arr[min] >= arr[j]){
				min = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	print(arr);
}


// -- Insertion sort 1 --
// i���� 0���� 1�� SIZE���� ������Ų��.
// j�� i - 1 ���� 0���� ��ȸ�ϸ鼭, arr[i] ���� ������ ��ġ�� Ž���Ѵ�.
// arr[j] > temp �� ���, arr[j + 1]�� ���� arr[j] ������ ���� �����.
// arr[j] <= temp �� ���, j + 1�� ��ġ�� arr[i] ���� �ִ´�.
void insertion1(int arr[]){
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}

		arr[j + 1] = temp;
	}

	print(arr);
}


// -- Insertion sort 2 --
// i���� 1���� 1�� SIZE���� ������Ų��.
// j�� 0 ���� i���� ��ȸ�ϸ鼭, arr[i] ���� ������ ��ġ�� Ž���Ѵ�.
// arr[i] < arr[j] �� ���, ���� j�� ���� index�� �����ϰ� �ݺ����� �������´�.
// temp �� arr[i]�� ���� ��, j�� i - 1 ���� index���� ��ȸ�ϸ鼭 arr[j + 1]�� ���� arr[j]������ �־� �о��ش�.
// arr[index]�� temp�� �ִ´�.
void insertion2(int arr[]) {
	int i, j;
	int index;
	int temp;

	for (i = 1; i < SIZE; i++) {
		index = i;

		for (j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				index = j;
				break;
			}
		}

		temp = arr[i];

		for (j = i - 1; j >= index; j--) {
			arr[j + 1] = arr[j];
		}
		arr[index] = temp;
	}

	print(arr);
}