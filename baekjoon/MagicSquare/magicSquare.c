#include <stdio.h>

#define MAX 15		// �������� �ִ� ũ��, �����ϸ� �� ũ�� ���� ���� �ִ�.

int main() {
	int arr[MAX][MAX] = { 0, };		// ������ 2���� �迭, 0���� �ʱ�ȭ �Ǿ���.
	int SIZE;						// �������� �Ҵ��� ũ��, MAX���� �۰ų� ���� ���� ����.
	int temp = 0;					// ���� �޽��� ����� ���� �ӽ� ����



	// input Ȯ��
	// 2�� ����̰ų�, 0���� �۰ų� ���ų�, MAX���� ū���, �ٽ� �Է��� �޴´�.
	do {
		if (temp++)
			printf("[ERROR] input error\nPlease insert a odd number.\n");

		printf("SIZE? : ");
		scanf_s("%d", &SIZE);
	} while (SIZE % 2 != 1 || SIZE > MAX || SIZE <= 0);
	


	// row = 0, col = size / 2�� �ʱ�ȭ
	// i, j : loof ����
	int row = 0;
	int col = SIZE / 2;
	int i, j;



	// 1 ~ size * size ���� �������� ���� ����
	// ��Ģ :	���� index�� ���� ����Ǿ� �ִٸ�, ���� ���� �ҷ���(row = row+2, col = col+1)
	//			size���� Ŀ���ٸ�, �迭�� ó�� row (�Ǵ� col)���� ������
	//			���簪�� ������ ��, row�� col�� 1�� ����
	//			row (�Ǵ� col)�� -1�̶�� �迭�� ������ row (�Ǵ� col)���� ������
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



	// �밢���� ���� ����ϱ� ���� ����
	int diagonal1 = 0;
	int diagonal2 = 0;
	// �� row (�Ǵ� col)�� ���� ����ϱ� ���� ����
	int sum;



	// m�� ����� �յ��� ���
	for (i = 0; i < SIZE; i++) {
		printf("\t");
	}
	printf("��\t");
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
		printf("��\t%d", sum);
		printf("\n");
	}

	for (i = 0; i < SIZE; i++) {
		printf("��\t");
	}
	printf("��\t");
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