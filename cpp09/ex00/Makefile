name = btc
cp = c++
flags = -Wall -Wextra -Werror -std=c++98 
src = main.cpp BitcoinExchange.cpp
obj = $(src:.cpp=.o)

all : $(name)

$(name) : $(obj) Makefile
	$(cp) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(cp) $(flags) -c $< -o $@

clean :
	rm -rf $(obj)

fclean : clean
	rm -rf $(name)

re : fclean all

.PHONY: all clean fclean re