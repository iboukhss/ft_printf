NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -L.
LDLIBS = -ltap -lftprintf

# Main sources
SRC_DIR = src/
SRC_FILES += ft_printf.c ft_vdprintf.c buffer_utils.c
SRC_FILES += ft_strlen.c ft_itoa.c ft_utoa.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS = $(SRCS:.c=.o)
INCS = include/ft_printf.h src/buffer_utils.h

# Test sources
TEST_SRCS = t/ft_printf.c
TEST_EXES = $(TEST_SRCS:.c=.t)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(INCS)
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
