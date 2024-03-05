CC := gcc
CFLAGS := -Wall -Wextra -Werror -O2

# Check if CROSS_COMPILE variable is specified
ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
endif

# Default target to build the writer application
all: writer

writer: writer.o
	$(CC) $(CFLAGS) -o $@ $^

writer.o: writer.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target to remove application and object files
clean:
	rm -f writer writer.o

.PHONY: all clean
