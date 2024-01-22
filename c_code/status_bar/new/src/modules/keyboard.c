#include "modules/keyboard.h"

#include <X11/XKBlib.h>
#include <X11/Xlib.h>
#include <X11/extensions/XKB.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "array.h"

void *get_keyboard_long_layout(Display *display) {
  if (!display) {
    return NULL;
  }

  XkbStateRec state;
  XkbDescPtr keyboard = NULL;
  char *buffer = malloc(KEYBOARD_LONG_MAX_SIZE * sizeof(char));
  char *layout = NULL;

  memset(buffer, 0, KEYBOARD_LONG_MAX_SIZE);

  if (XkbGetState(display, XkbUseCoreKbd, &state)) {
    goto cleanup;
  }

  keyboard = XkbGetKeyboard(display, XkbAllComponentsMask, XkbUseCoreKbd);

  if (!keyboard) {
    goto cleanup;
  }

  layout = XGetAtomName(display, keyboard->names->groups[state.group]);

  strncpy(buffer, layout, KEYBOARD_LONG_MAX_SIZE - 1);

  goto cleanup;

cleanup:
  if (keyboard) {
    XkbFreeKeyboard(keyboard, XkbAllComponentsMask, XkbUseCoreKbd);
  }

  if (layout) {
    XFree(layout);
  }

  return buffer;
}

void *get_keyboard_short_layout(Display *display) {
  if (!display) {
    return NULL;
  }

  XkbStateRec state = {0};
  XkbDescPtr keyboard = NULL;
  char *symbols = NULL;
  char *buffer = malloc(KEYBOARD_SHORT_MAX_SIZE * sizeof(char));
  char *layout = NULL;

  keyboard = XkbGetKeyboard(display, XkbSymbolsNameMask, XkbUseCoreKbd);

  if (!keyboard) {
    goto cleanup;
  }

  if (XkbGetNames(display, XkbSymbolsNameMask, keyboard)) {
    goto cleanup;
  }

  if (XkbGetState(display, XkbUseCoreKbd, &state)) {
    goto cleanup;
  }

  symbols = XGetAtomName(display, keyboard->names->symbols);

  if (!symbols) {
    goto cleanup;
  }

  const unsigned char group = state.group;
  unsigned char layouts_count = 0;
  const char *symbols_delimeter = "+:";
  const char *invalid_layouts[] = {"evdev", "inet", "pc", "base"};
  char *layout_save = NULL;

  layout = strtok_r(symbols, symbols_delimeter, &layout_save);

  while (layout != NULL) {
    if (!is_string_in_array(invalid_layouts, ARRAY_LENGTH(invalid_layouts),
                            layout)) {
      layouts_count++;
    }

    if (layouts_count - 1 == group) {
      layout = strdup(layout);

      break;
    }

    layout = strtok_r(NULL, symbols_delimeter, &layout_save);
  }

  strncpy(buffer, layout, KEYBOARD_SHORT_MAX_SIZE);

  goto cleanup;

cleanup:
  if (keyboard) {
    XkbFreeKeyboard(keyboard, XkbSymbolsNameMask, XkbUseCoreKbd);
  }

  if (symbols) {
    XFree(symbols);
  }

  if (layout) {
    XFree(layout);
  }

  return layout;
}

void *get_keyboard_layout(enum KeyboardTypes type) {
  Display *display = NULL;
  char *layout = NULL;

  display = XOpenDisplay(NULL);

  if (!display) {
    goto cleanup;
  }

  switch (type) {
    case Long:
      layout = get_keyboard_long_layout(display);

      break;

    case Short:
      layout = get_keyboard_short_layout(display);

      break;
  }

  goto cleanup;

cleanup:
  if (display) {
    XCloseDisplay(display);
  }

  return layout;
}
