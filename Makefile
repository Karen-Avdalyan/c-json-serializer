NAME = json_parser.a

CC	=	cc

CFLAGS = -Wall -Wextra -Werror

ALL_SRCS = $(wildcard *.c ./get_next_line/*.c)

SRCS =  $(ALL_SRCS)

OBJS = $(patsubst %.c, %.o, $(SRCS))


RM = rm -f

AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
