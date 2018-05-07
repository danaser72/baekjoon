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
// i값을 0부터 1씩 SIZE 까지 증가시킨다.
// j가 0 부터 SIZE - 1까지 순회한다.
// arr[j] >= arr[j + 1] 인 경우, 두 값을 바꾼다.
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
// i값을 0부터 1씩 SIZE - 1 까지 증가시킨다.
// j가 i + 1 부터 SIZE - 1 까지 순회하면서, 가장 작은 arr[j] 값의 index를 min에 넣는다.
// arr[min] 값과 arr[i] 값을 바꾼다.
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
// i값을 0부터 1씩 SIZE까지 증가시킨다.
// j가 i - 1 부터 0까지 순회하면서, arr[i] 값의 적절한 위치를 탐색한다.
// arr[j] > temp 인 경우, arr[j + 1]의 값을 arr[j] 값으로 덮어 씌운다.
// arr[j] <= temp 인 경우, j + 1의 위치에 arr[i] 값을 넣는다.
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
// i값을 1부터 1씩 SIZE까지 증가시킨다.
// j가 0 부터 i까지 순회하면서, arr[i] 값의 적절한 위치를 탐색한다.
// arr[i] < arr[j] 인 경우, 현재 j의 값을 index에 저장하고 반복문을 빠져나온다.
// temp 에 arr[i]를 넣은 후, j를 i - 1 부터 index까지 순회하면서 arr[j + 1]의 값을 arr[j]값으로 넣어 밀어준다.
// arr[index]에 temp를 넣는다.
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