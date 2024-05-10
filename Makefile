NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g -MMD
LDFLAGS = -L.
LDLIBS = -ltap -lftprintf

# Main sources
MAIN_DIR = ./src/
MAIN_FILES = ft_printf.c ft_vdprintf.c append.c append_extras.c parse.c
MAIN_INC_FILES = append.h parse.h
MAIN_SRCS = $(addprefix $(MAIN_DIR),$(MAIN_FILES))
MAIN_INC_SRCS = $(addprefix $(MAIN_DIR),$(MAIN_INC_FILES))

# Library sources
LIBFT_DIR = ./libft/
LIBFT_FILES += ft_strlen.c ft_isdigit.c ft_memset.c
LIBFT_FILES += ft_u64toa.c ft_u64toa_base.c ft_i64toa.c
LIBFT_SRCS = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))

# Headers
INC_DIR = ./include/
INC_FILES = ft_printf.h libft.h
INC_SRCS = $(addprefix $(INC_DIR),$(INC_FILES))

# Target sources
SRCS = $(MAIN_SRCS) $(LIBFT_SRCS)
INCS = $(MAIN_INC_SRCS) $(INC_SRCS)
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# Test sources
TEST_DIR = ./t/
TEST_FILES = specifiers.c prefixes.c precision.c width.c
TEST_SRCS = $(addprefix $(TEST_DIR),$(TEST_FILES))
TEST_EXES = $(TEST_SRCS:.c=.t)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

bonus: all

norm:
	-norminette $(SRCS) $(INCS)

# Testing
tests: $(TEST_EXES)

%.t: %.c libtap.a libftprintf.a
	$(CC) $(CFLAGS) -I$(INC_DIR) $< $(LDFLAGS) $(LDLIBS) -o $@

libtap.a: t/tap.o
	ar -rcs $@ $<

tap.o: t/tap.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)
	rm -f t/*o t/*.d

fclean: clean
	rm -f *.a
	rm -f t/*.t

re: fclean all

# Dependencies
-include $(DEPS)

.PHONY: all bonus norm tests clean fclean re
