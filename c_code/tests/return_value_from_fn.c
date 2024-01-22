#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hy(char *hyt) {
	return hyt;
}

char *fn() {
	char *val = "heko";
	char *ghyt = malloc(6 * sizeof(char));

	memcpy(val, ghyt, 6);

	free(ghyt);
	
	return val;
}

int main(void) {
	char *str = fn();

	printf("%s\n", str);
}
