name = iter
flags = -Wall -Wextra -Werror -std=c++98
c++ = c++

all : $(name)

$(name) : main.o Makefile
	$(c++) $(flags) main.cpp -o $(name)

clean:
	rm -rf main.o

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all re clean fclean
