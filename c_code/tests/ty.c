#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
  printf("size of int: %lu\n", sizeof(int));
  printf("size of uint8: %lu\n", sizeof(uint8_t));
  printf("size of uint16: %lu\n", sizeof(uint16_t));
  printf("size of char: %lu\n", sizeof(char));
  printf("size of uchar: %lu\n", sizeof(unsigned char));

  return EXIT_SUCCESS;
}
