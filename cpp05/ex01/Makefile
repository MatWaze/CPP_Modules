name = form
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98
src = main.cpp Bureaucrat.cpp
obj = $(src:.cpp=.o)

$(name): $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o: %.cpp
	$(c++) $(flags) -c  $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)


re: fclean all

.PHONY: all clean fclean re
	