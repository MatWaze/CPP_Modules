name = clapTrap
c++ = c++
cflags = -Wall -Wextra -Werror
src = main.cpp ClapTrap.cpp
obj = $(src:.cpp=.o)

all : $(name)

sanitize : flags += -g -fsanitize=address
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