# Program name
NAME = cpp01-ex00

# Compiler
CXX = c++

# Compiler flags
#  Wall: enable common warnings
#  Wextra: enable extra warnings
#  Werror: treat warnings as errors
#  std=c++98: compile using the C++98 standard
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp			\
       newZombie.cpp	\
	   randomChump.cpp	\
	   Zombie.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
