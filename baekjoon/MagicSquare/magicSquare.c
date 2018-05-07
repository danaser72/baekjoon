#include <stdio.h>

#define MAX 15		// 마방진의 최대 크기, 수정하면 더 크게 만들 수도 있다.

int main() {
	int arr[MAX][MAX] = { 0, };		// 마방진 2차원 배열, 0으로 초기화 되었다.
	int SIZE;						// 마방진에 할당할 크기, MAX보다 작거나 같은 수가 들어간다.
	int temp = 0;					// 에러 메시지 출력을 위한 임시 변수



	// input 확인
	// 2의 배수이거나, 0보다 작거나 같거나, MAX보다 큰경우, 다시 입력을 받는다.
	do {
		if (temp++)
			printf("[ERROR] input error\nPlease insert a odd number.\n");

		printf("SIZE? : ");
		scanf_s("%d", &SIZE);
	} while (SIZE % 2 != 1 || SIZE > MAX || SIZE <= 0);
	


	// row = 0, col = size / 2로 초기화
	// i, j : loof 변수
	int row = 0;
	int col = SIZE / 2;
	int i, j;



	// 1 ~ size * size 까지 마방진에 값을 대입
	// 규칙 :	현재 index에 값이 저장되어 있다면, 이전 값을 불러옴(row = row+2, col = col+1)
	//			size보다 커진다면, 배열의 처음 row (또는 col)부터 시작함
	//			현재값을 저장한 후, row와 col을 1씩 빼줌
	//			row (또는 col)가 -1이라면 배열의 마지막 row (또는 col)부터 시작함
	for (i = 0; i < SIZE * SIZE; i++) {
		if (arr[row][col] != 0) {
			row += 2;
			col++;

			if (row >= SIZE)
				row -= SIZE;

			if (col >= SIZE)
				col -= SIZE;

		}
		arr[row][col] = i + 1;

		row--;
		col--;

		if (row == -1)
			row = SIZE - 1;
		if (col == -1)
			col = SIZE - 1;
	}



	// 대각선의 합을 출력하기 위한 변수
	int diagonal1 = 0;
	int diagonal2 = 0;
	// 각 row (또는 col)의 합을 출력하기 위한 변수
	int sum;



	// m의 값들과 합들을 출력
	for (i = 0; i < SIZE; i++) {
		printf("\t");
	}
	printf("↗\t");
	for (i = SIZE - 1, j = 0; i >= 0 && j < SIZE; i--, j++) {
			diagonal1 += arr[i][j];
	}
	printf("%d\n", diagonal1);

	for (i = 0; i < SIZE; i++) {
		sum = 0;
		for (j = 0; j < SIZE; j++) {
			printf("%d\t", arr[i][j]);
			sum += arr[i][j];
		}
		printf("→\t%d", sum);
		printf("\n");
	}

	for (i = 0; i < SIZE; i++) {
		printf("↓\t");
	}
	printf("↘\t");
	for (i = 0, j = SIZE - 1; i < SIZE && j >= 0; i++, j--) {
		diagonal2 += arr[i][j];
	}
	printf("%d\n", diagonal2);

	for (j = 0; j < SIZE; j++) {
		sum = 0;
		for (i = 0; i < SIZE; i++) {
			sum += arr[i][j];
		}
		printf("%d\t", sum);
	}

	printf("\n");

	return 0;
}