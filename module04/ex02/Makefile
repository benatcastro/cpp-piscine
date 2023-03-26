NAME		=	Abstract
CXX			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic #-fsanitize=address
OBJS		=	main.o Animal.o Cat.o Dog.o Brain.o
RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

run_s: s
	./$(NAME_S)

run: all
	./$(NAME)

leaks: all
	./$(NAME)
	leaks $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_S)


.PHONY: all run clean fclean
