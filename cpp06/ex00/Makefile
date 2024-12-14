name = convert
c++ = c++
flags = -Wall -Wextra -Werror
src = main.cpp ScalarConverter.cpp typeCheck.cpp convertTypes.cpp
obj = $(src:.cpp=.o)

all: $(name)

$(name) : $(obj) Makefile
	$(c++) $(obj) -o $(name)

%.o : %.cpp
	$(c++) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re