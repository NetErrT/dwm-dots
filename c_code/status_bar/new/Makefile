MAKEFLAGS += --no-builtin-rules

.SUFFIXES:
.PHONY: all release debug clean

CC ?= clang
LIBS := $(shell pkg-config --libs x11 alsa)
CFLAGS := $(CFLAGS) -std=c99 -pedantic -Wall -Wextra -Iinclude -D_POSIX_C_SOURCE=200809L

SRC_DIR ?= src
BUILD_DIR ?= build
CACHE_DIR ?= $(BUILD_DIR)/cache
BIN_DIR ?= $(BUILD_DIR)/bin

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(CACHE_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: debug

debug: CFLAGS += -fsanitize=address -ggdb -Og
debug: $(BIN_DIR)/debug

release: CFLAGS += -O2 -pipe -march=native
release: $(BIN_DIR)/release

clean:
	rm -rf $(BUILD_DIR)

$(CACHE_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

$(BIN_DIR)/%: $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

