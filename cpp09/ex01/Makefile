cp = c++
name = RPN
flags = -Wall -Wextra -Werror -std=c++98
src = main.cpp RPN.cpp
obj = $(src:.cpp=.o)

all : $(name)

$(name) : Makefile $(obj)
	$(cp) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(cp) $(flags) -c $< -o $@

clean : 
	rm -rf $(obj)

fclean : clean
	rm -rf $(name)

re : fclean all

.PHONY: all clean fclean re