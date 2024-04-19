NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g

SRC_DIR = src/
SRC_FILES += ft_printf.c ft_vdprintf.c formats.c formats_extra.c
SRC_FILES += ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_i32toa.c ft_u64toa.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_FILES))

INC_DIR = include/
INC_FILES = ft_printf.h
INCS = $(addprefix $(INC_DIR),$(INC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

norm:
	-norminette $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
