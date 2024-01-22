#include <stdio.h>
#include <stdlib.h>

#include "modules/date.h"
#include "modules/keyboard.h"

int main(void) {
	char *layout = get_keyboard_layout(Long);

	if (!layout) {
		return EXIT_FAILURE;
	}

	printf("%s\n", layout);

	free(layout);

  return EXIT_SUCCESS;
}
