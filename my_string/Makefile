CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = test_functions
OBJS = test_functions.o my_string.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
