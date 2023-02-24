NAME		=	phonebook
CXX			=	clang++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
OBJS		=	PhoneBook.o Contact.o ValidateInput.o
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
