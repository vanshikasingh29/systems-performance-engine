CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -O2 -g

INCLUDE = -Iinclude


SOURCES = \
src/allocator.c \
src/bitops.c \
src/cpu.c \
src/benchmark.c \
src/algorithms.c


PROGRAM = systems_toolkit

TEST_PROGRAM = system_tests


all: $(PROGRAM)


$(PROGRAM): examples/main.c $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) \
	examples/main.c \
	$(SOURCES) \
	-o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


$(TEST_PROGRAM): tests/test_systems.c $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_systems.c \
	$(SOURCES) \
	-o $(TEST_PROGRAM)


test: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean