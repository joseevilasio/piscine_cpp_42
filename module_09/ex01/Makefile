NAME = RPN

SRCS = main.cpp RPN.cpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I./ $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re