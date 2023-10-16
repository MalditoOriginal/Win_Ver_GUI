# Compiler and compiler flags
CC = i686-w64-mingw32-gcc  # This should be the MinGW compiler executable

# Compiler flags for MinGW
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
