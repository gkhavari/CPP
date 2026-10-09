# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/09 17:28:48 by gkhavari          #+#    #+#              #
#    Updated: 2026/10/09 17:28:50 by gkhavari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = 	megaphone.cpp\

OBJ = $(SRC:.cpp=.o)

NAME = megaphone

all: $(NAME)

$(NAME):$(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
