NAME		=	Zombie
CXX			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJS		=	main.o newZombie.o randomChump.o Zombie.cpp
RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

run: all
	./$(NAME)

re: fclean all
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


.PHONY: all run clean fclean
