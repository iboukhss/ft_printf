NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g
LDFLAGS = -L.
LDLIBS = -ltap -lftprintf

# Main sources
SRCS += ft_printf.c ft_vdprintf.c append.c append_extras.c
SRCS += ft_memset.c ft_strlen.c ft_isdigit.c
OBJS = $(SRCS:.c=.o)

# Test sources
TEST_SRCS = t/ft_printf.c
TEST_EXES = $(TEST_SRCS:.c=.t)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c ft_printf.h append.h
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_EXES)

libtap.a: t/tap.o
	ar rcs $@ $<

t/tap.o: t/tap.c t/tap.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.t: %.o libtap.a libftprintf.a
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

norm:
	-norminette $(SRCS) $(INCS)

clean:
	rm -f *.o
	rm -f src/*.o

fclean: clean
	rm -f *.a
	rm -f t/*.t

re: fclean all

.PHONY: all clean fclean re
