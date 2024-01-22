#include "modules/date.h"

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void *get_date(const char *format) {
  if (!format) {
    errno = EINVAL;
    return NULL;
  }

  char *buffer = malloc(DATE_MAX_SIZE * sizeof(char));
  time_t timer = time(NULL);
  struct tm info;

  if (!localtime_r(&timer, &info)) {
    return NULL;
  }

  strftime(buffer, DATE_MAX_SIZE, format, &info);

  return buffer;
}
