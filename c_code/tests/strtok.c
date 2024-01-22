#include <string.h>
#include <stdio.h>

int main(void) {
	char str[] = "hello world";
	char *token = strtok(str, " ");

	printf("%s", token);
}
