NAME			=		megaphone
CXX 			=		g++
CPPFLAGS	=		-Wall -Wextra -Werror 
OBJS			=		megaphone.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)		

run: all
	./$(NAME)
