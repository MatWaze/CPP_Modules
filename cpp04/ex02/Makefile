name = brain
c++ = c++
flags = -Wall -Wextra -Werror
src = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
obj = $(src:.cpp=.o)

all : $(name)

sanitize : flags += -g3 -fsanitize=address
sanitize : all

$(name) : $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@

clean :
	rm -f $(obj)

fclean : clean
	rm -f $(name)

re : fclean all

.PHONY: all clean fclean
