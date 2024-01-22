#pragma once

#include <X11/Xlib.h>
#include <stdint.h>

#define KEYBOARD_LONG_MAX_SIZE 84
#define KEYBOARD_SHORT_MAX_SIZE 3

enum KeyboardTypes {
	Long,
	Short,
};

void *get_keyboard_long_layout(Display *display);
void *get_keyboard_short_layout(Display *display);
void *get_keyboard_layout(enum KeyboardTypes type);
