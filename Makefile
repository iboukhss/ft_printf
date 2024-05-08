# Target
NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -g -MMD

# Main sources
MAIN_DIR = ./src/
MAIN_FILES = ft_printf.c ft_vdprintf.c append.c append_extras.c parse.c
MAIN_INC_FILES = append.h parse.h
MAIN_SRCS = $(addprefix $(MAIN_DIR),$(MAIN_FILES))
MAIN_INC_SRCS = $(addprefix $(MAIN_DIR),$(MAIN_INC_FILES))

# Library sources
LIBFT_DIR = ./libft/
LIBFT_FILES += ft_strlen.c ft_isdigit.c ft_memset.c
LIBFT_FILES += ft_u64toa.c ft_u64toa_base.c ft_i64toa_abs.c
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

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

bonus: all

norm:
	-norminette $(SRCS) $(INCS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Dependencies
-include $(DEPS)

.PHONY: all bonus norm clean fclean re
