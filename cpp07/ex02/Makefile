name = array
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98# -fsanitize=address

all : $(name)

$(name) : main2.o Makefile
	$(c++) $(flags) main2.cpp -o $(name)

clean:
	rm -rf main2.o

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re
