#include <stdio.h>

int main() {
	int line = 0;
	int i, j;

	line = 5;

	for (i = 0; i < line; i++) {
		for (j = 0; j < line; j++) {
			if (i <= line / 2) {
				if (j > line / 2 + i || j < line / 2 - i) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			else {
				if (j < i - line / 2 || j > line - i + line / 2 - 1) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
		}
		printf("\n");
	}

	return 0;

	/*
	do {
		if (line % 2 == 0) {
			printf("홀수로 입력해주세요.\n");
		}
		printf("LINE : ");
		scanf_s("%d", &line);
	} while (line % 2 == 0);
	*/
	/*
	for (i = 0; i < line; i++) {
		if (i <= line / 2) {
			for (j = i; j < line / 2; j++) {
				printf(" ");
			}
			printf("*");
			for (j = 0; j < i; j++) {
				printf("**");
			}
			printf("\n");
		}
		else {
			for (j = line / 2; j < i; j++) {
				printf(" ");
			}
			printf("*");
			for (j = i + 1; j < line; j++) {
				printf("**");
			}
			printf("\n");
		}
	}*/
}