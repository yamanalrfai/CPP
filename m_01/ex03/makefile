CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = unnecessary_violence

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
