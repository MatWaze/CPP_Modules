name = convert
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98
src = test.cpp ScalarConverter.cpp typeCheck.cpp convertTypes.cpp
obj = $(src:.cpp=.o)

all: $(name)

$(name) : $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re