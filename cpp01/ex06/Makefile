name = harlFilter
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98 -pedantic
src = main.cpp Harl.cpp
obj = $(src:.o=.c)

all : $(name)

sanitize : flags += -g -fsanitize=address
sanitize : all

$(name) : $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o : %.c
	$(c++) $(flags) -c $< -o $@
	
clean : 
	rm -f $(obj)

fclean : clean
	rm -f $(name)

re : fclean all

.PHONY: all clean fclean