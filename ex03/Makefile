NAME = intern
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/
SRCS = $(SRC_DIR)Bureaucrat.cpp $(SRC_DIR)AForm.cpp $(SRC_DIR)PresidentialPardonForm.cpp $(SRC_DIR)RobotomyRequestForm.cpp $(SRC_DIR)ShrubberyCreationForm.cpp $(SRC_DIR)Intern.cpp $(SRC_DIR)main.cpp
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
HEADERS = $(INC_DIR)Bureaucrat.hpp $(INC_DIR)AForm.hpp $(INC_DIR)PresidentialPardonForm.hpp $(INC_DIR)RobotomyRequestForm.hpp $(INC_DIR)ShrubberyCreationForm.hpp $(INC_DIR)Intern.hpp

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
