NAME		=	Polymorphism
NAME_S		=	Polymorphism_S
CXX			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic #-fsanitize=address
SANI		=	-fsanitize=address
OBJS		=	main.o Animal.o Cat.o Dog.o Brain.o
RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

s: $(NAME_S)

$(NAME_S): $(OBJS)
	$(eval $(CPPFLAGS) += -fsantize=adress)
	$(CXX) $(CPPFLAGS) $(SANI) $(OBJS) -o $(NAME_S)

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
