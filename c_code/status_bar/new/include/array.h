#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define ARRAY_LENGTH(array) sizeof(array) / sizeof(array[0])

bool is_string_in_array(const char *array[], size_t size,
                        const char *search_string);
