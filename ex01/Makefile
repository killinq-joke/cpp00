# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 14:22:25 by ztouzri           #+#    #+#              #
#    Updated: 2021/07/05 14:22:26 by ztouzri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= contact2000
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.cpp phonebook.cpp
OBJS	= $(SRCS:cpp=o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
