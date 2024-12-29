name = mutant
flags = -std=c++98 -fsanitize=address -Wall -Wextra -Werror

all: $(name)

$(name) : Makefile main.o
	c++ $(flags) main.cpp -o $(name)

%.o : %.cpp
	c++ $(flags) -c $< -o $@

clean:
	rm -rf main.o

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all re clean fclean