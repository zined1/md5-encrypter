CC=gcc
CFLAGS=-lm -Wall -Wextra -pedantic -Werror -std=c99
OBJS=src/md5encrypter.c
NAME=md5encrypter
all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

check:
	./test/check.py ${NUMBER}
clean:
	rm md5encrypter

.PHONY: all clean check

