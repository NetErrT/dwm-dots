#include "array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_string_in_array(const char *array[], size_t size,
                        const char *search_string) {
  for (size_t i = 0; i < size; i++) {
    const char *item = array[i];

    if (!strncmp(item, search_string, strlen(search_string))) {
      return true;
    }
  }

  return false;
}
