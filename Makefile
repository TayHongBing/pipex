# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:54:35 by thong-bi          #+#    #+#              #
#    Updated: 2023/03/08 16:54:35 by thong-bi         ###   ########.fr        #
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

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o pipex

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


