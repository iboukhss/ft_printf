NAME = libftprintf.a
CC = cc
CFLAGS := -Wall -Wextra -Werror -Iinclude
#CFLAGS += -g3 -MMD -fsanitize=address,undefined
#LDFLAGS = -L.
#LDLIBS = -ltap -lftprintf

vpath %.c src libft
vpath %.h src include

# Main sources
SRCS := ft_printf.c ft_vdprintf.c parse.c
SRCS += buffer.c append.c append_extras.c
INCS := ft_printf.h append.h parse.h buffer.h

# Library sources
SRCS += ft_strlen.c ft_strnlen.c ft_strscpy.c ft_memset.c
SRCS += ft_isdigit.c ft_islower.c ft_toupper.c ft_strupr.c
SRCS += ft_u64toa.c ft_u64toa_hex.c ft_i64toa_abs.c
INCS += libft.h

# Build deps
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# Test sources
#TEST_SRCS := specifiers.c prefixes.c precision.c width.c
#TEST_SRCS += width_and_precision.c mixed_flags.c align.c zero_padding.c
#TEST_EXES = $(TEST_SRCS:.c=.t)

# Pattern rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#%.t: %.c libtap.a libftprintf.a
#	$(CC) $(CFLAGS) $< $(LDFLAGS) $(LDLIBS) -o $@

# Target rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: all

#tests: $(TEST_EXES)

#libtap.a: tap.o
#	ar rcs $@ $<

#run: $(TEST_EXES)
#	prove $^

#norm: $(SRCS) $(INCS)
#	-norminette $^

clean:
	rm -f *.o *.d

fclean: clean
	rm -f *.a *.t

re: fclean all

-include $(DEPS)

.PHONY: all bonus norm tests run clean fclean re
