name = base
c++ = c++
flags = -Wall -Wextra -Werror
src = main.cpp Base.cpp tryCast.cpp
obj = $(src:.cpp=.o)

all: $(name)

$(name): $(obj)
	$(c++) $(flags) $(obj) -o $(name)

%.o : %.cpp
	$(c++) $(flags) -c $< -o $@ 

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re
