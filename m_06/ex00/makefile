CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex00
SRCS = main.cpp  ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re