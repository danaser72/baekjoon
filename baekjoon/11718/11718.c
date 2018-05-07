#include <stdio.h>

int main() {
	int i;
	char text[101];

	while (gets(text) != EOF){
		fflush(stdin);
		printf("%s\n", text);
	}

	return 0;
}