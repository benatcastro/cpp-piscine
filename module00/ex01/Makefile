NAME		=	phonebook
CXX			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror
OBJS		=	PhoneBook.o Contact.o
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
