cp = c++
name = PmergeMe
flags = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
src = main2.cpp
obj = $(src:.cpp=.o)

all : $(name)

$(name) : Makefile $(obj)
	$(cp) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(cp) $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re
