name = account
c++ = c++ -Wall -Wextra -Werror
src = Account.cpp tests.cpp
obj = $(src:.cpp=.o)

all : $(name)

$(name) : $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@
	
clean :
	rm -f $(obj)

fclean : clean
	rm -f $(name)

re : fclean all

.PHONY: all clean fclean re