NAME		= interfaces.exe

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
				AAMateria.cpp \
				Ice.cpp \
				Cure.cpp \
				ICharacter.cpp \
				//WrongCat.cpp \
				//Brain.cpp

HEADERS 	= AAMateria.hpp \
				Ice.hpp \
				Cure.hpp \
				ICharacter.hpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Built $(NAME) successfully"

%.o: %.cpp $(HEADERS) Makefile
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@rm -f $(OBJS)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

re: fclean all

.PHONY: all clean fclean re