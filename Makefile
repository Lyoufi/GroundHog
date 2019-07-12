##
## EPITECH PROJECT, 2019
## CNA_groundhog_2018
## File description:
## Makefile
##

SRC = src/main.cpp	\
	src/Groundhog.cpp	\
	src/computations.cpp
INC = include/

CXX = g++
CXXFLAGS = -W -Wall -Wextra -I include/
NAME = groundhog

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re