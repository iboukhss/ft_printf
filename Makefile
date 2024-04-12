NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g -fsanitize=undefined
LDFLAGS = -L.
LDLIBS = -ltap -lftprintf

SRCS = 
OBJS = $(SRCS:.c=.o)

TEST_SRCS = 
TEST_EXES = $(TEST_SRCS:.c=.t)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

libtap.a: tap.o
	ar rcs $@ $<

tap.o: tap.c tap.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $<

%.t: %.c libtap.a libftprintf.a
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

tests: $(TEST_EXES)

norm:
	-norminette $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f *.a
	rm -f t/*.t

re: fclean all

.PHONY: all norm clean fclean re
