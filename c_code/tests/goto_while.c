#include <stdio.h>

int main(void) {
  int i = 0;

loop:
	i++;

	printf("%d\n", i);

  if (i < 10) {
    goto loop;
  }
}
