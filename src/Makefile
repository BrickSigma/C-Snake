# Makefile for project
# Make sure you have raylib installed on your system

CC := gcc
CFLAGS := -O2 -Wall -std=c99 -Wno-missing-braces

LINKERS :=

ifeq ($(OS), Windows_NT)
	# For windows
	RAYLIB_PATH = C:/raylib/src
	LINKERS += -L$(RAYLIB_PATH) -I$(RAYLIB_PATH) -lraylib -lgdi32 -lwinmm 
else
	LINKERS += -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

SRC = *.c  # Directory to all source files
OUT = main.out  # Name of the output exe file

build: $(SRC)
	$(CC) $^ -o $(OUT) $(CFLAGS) -I. $(LINKERS)

clean:
	rm -f *.out