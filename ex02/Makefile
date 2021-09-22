# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 14:22:19 by ztouzri           #+#    #+#              #
#    Updated: 2021/07/05 16:19:27 by ztouzri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror

SRCS	= Account.cpp tests.cpp
OBJS	= $(SRCS:cpp=o)

%o: %cpp
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
