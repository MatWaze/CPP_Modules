name = easyfind
c++ = c++
flags = -Wall -Wextra -Werror #-std=c++98

all: $(name)

$(name): main.o Makefile
	$(c++) $(flags) main.cpp -o $(name)

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@

clean:
	rm -rf main.o

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re