# Makefile (cpp00-ex00)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp
OBJ = megaphone.o

EXEC = megaphone

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
