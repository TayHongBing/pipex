# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:54:35 by thong-bi          #+#    #+#              #
#    Updated: 2023/03/08 16:27:56 by thong-bi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = pipex
SRCS = free.c\
	   pipex.c\
	   error.c\
	   process.c\
	   ft_split.c\
	   ft_strdup.c\
	   ft_strjoin.c\
	   ft_substr.c\
	   ft_strncmp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o pipex


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all pipex bonus clean fclean re

