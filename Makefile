# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall

# Executable name
EXECUTABLE = win_ver.exe

# Source files and object files
SRC = win_ver.c
OBJ = $(SRC:.c=.o)

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(EXECUTABLE) $(OBJ)

.PHONY: all clean
