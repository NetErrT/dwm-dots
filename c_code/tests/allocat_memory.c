#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print(const char *message, void *pointer) {
  printf("%s: %p\n", message, pointer);
}

int main(void) {
	uint8_t integers[] = { 20, 40, 60, 255 };

	printf("%d", *integers);

  return EXIT_SUCCESS;
}
