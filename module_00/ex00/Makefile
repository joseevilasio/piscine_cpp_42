NAME = megaphone

SRCS = megaphone.cpp

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

#clean:

fclean:
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re