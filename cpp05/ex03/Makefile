name = intern
c++ = c++
flags = -Wall -Wextra -Werror -std=c++98
src = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
obj = $(src:.cpp=.o)

all: $(name)

sanitize: flags += -fsanitize=address
sanitize: all

$(name): $(obj) Makefile
	$(c++) $(flags) $(obj) -o $(name)

%.o: %.cpp Makefile
	$(c++) $(flags) -c  $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all

.PHONY: all clean fclean re sanitize	