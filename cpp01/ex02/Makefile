name = refptr
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98 -pedantic
src = main.cpp
obj = $(src:.cpp=.o)

all : $(name)

sanitize : flags += -g -fsanitize=thread
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