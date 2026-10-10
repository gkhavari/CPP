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

NAME = megaphone

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = 	megaphone.cpp\

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
