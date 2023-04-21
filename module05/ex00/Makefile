NAME		=	Bureaucrat
NAME_SANI	=	$(addsuffix _sani, $(NAME))
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
SANI_FLAG	=	-fsanitize=address -g3
OBJDIR		=	objs/
OBJDIR_SANI	=	objs_sani/
PCHDIR		=	pch/
SRCS		=	$(wildcard *.cpp)
PCH_SRC 	=	$(wildcard *.hpp)
PCH_OUT 	=	$(addprefix $(PCHDIR), $(PCH_SRC:.hpp=.hpp.gch))
OBJS	 	=	$(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
OBJS_SANI   = 	$(addprefix $(OBJDIR_SANI), $(SRCS:.cpp=_sani.o))


MKDIR		=	mkdir -p
RM			=	rm -fr
ECHO		=	echo


#.SILENT:

all: $(NAME) $(NAME_SANI)

$(NAME_SANI): $(OBJS_SANI)
	$(CXX) $(CXXFLAGS) $(SANI_FLAG) $(OBJS) -I $(PCHDIR) -o $(NAME_SANI)
#	printf "$(B_RED)CREATING $(NC)$(B_WHT)%s$(NC)$(B_RED)SANI EXECUTABLE: $(B_WHT)$(NAME_SANI) $(NC)\n"

$(OBJS_SANI): $(SRCS) $(PCH_OUT)
	@$(MKDIR) $(OBJDIR_SANI)
	$(CXX) $(CXXFLAGS) $(SANI_FLAG) -c -o $@ $<
#	printf "$(B_RED)Sani Compiling: $(NC)$(B_WHT)%s$(NC)\n" $(notdir $@)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -I $(PCHDIR) -o $(NAME)
#	printf "$(B_BLU)CREATING $(NC)$(B_WHT)%s$(NC)$(B_BLU)EXECUTABLE: $(B_WHT)$(NAME) $(NC)\n"

$(OBJDIR)%.o: %.cpp $(PCH_OUT)
	@$(MKDIR) $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
#	printf "$(B_CYN)Compiling: $(NC)$(B_WHT)%s$(NC)\n" $(notdir $@)

$(PCH_OUT): $(PCH_SRC)
	@$(MKDIR) $(PCHDIR)
	$(CXX) $(CXXFLAGS) -o $@ $<
#	printf "$(B_CYN)Compiling: $(NC)$(B_WHT)%s$(NC)\n" $(notdir $@)

sani: $(NAME_SANI)
	./$(NAME_SANI)

run: all
	./$(NAME)

re: fclean all

clean:
	@$(RM) $(OBJDIR)
	@$(RM) $(PCHDIR)
	@$(RM) $(OBJDIR_SANI)

const: all
	@$(ECHO) "n constructors ->"
	@./$(NAME) | grep "cons" | wc -l
	@$(ECHO) "n destructors ->"
	@./$(NAME) | grep "dest" | wc -l
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_SANI)


BLK		=	\e[0;30m
RED		=	\e[0;31m
GRN		=	\e[0;32m
YEL		=	\e[0;33m
BLU		=	\e[0;34m
MAG		=	\e[0;35m
CYN		=	\e[0;36m
WHT		=	\e[0;37m

B_BLK	=	\e[1;30m
B_RED	=	\e[1;31m
B_GRN	=	\e[1;32m
B_YEL	=	\e[1;33m
B_BLU	=	\e[1;34m
B_MAG	=	\e[1;35m
B_CYN	=	\e[1;36m
B_WHT	=	\e[1;37m
NC	=	\e[0m

.PHONY: all run clean fclean const
