# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghazette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 13:29:01 by ghazette          #+#    #+#              #
#    Updated: 2017/11/30 21:21:10 by ghazette    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS = ft_atoi\
		ft_isalnum\
		ft_isalpha\
		ft_isascii\
		ft_isdigit\
		ft_isprint\
		ft_isspace\
		ft_tolower\
		ft_toupper\
		ft_strcat\
		ft_strncat\
		ft_strlcat\
		ft_strchr\
		ft_strrchr\
		ft_strcmp\
		ft_strncmp\
		ft_strcpy\
		ft_strncpy\
		ft_strdup\
		ft_strnstr\
		ft_strstr\
		ft_strlen\
		ft_memalloc\
		ft_memdel\
		ft_strnew\
		ft_strdel\
		ft_strclr\
		ft_striter\
		ft_striteri\
		ft_strmap\
		ft_strmapi\
		ft_strequ\
		ft_strnequ\
		ft_putchar\
		ft_putchar_fd\
		ft_putstr\
		ft_putstr_fd\
		ft_putendl\
		ft_putendl_fd\
		ft_putnbr\
		ft_putnbr_fd\
		ft_itoa\
		ft_bzero\
		ft_memccpy\
		ft_memchr\
		ft_memcmp\
		ft_memcpy\
		ft_memdel\
		ft_memmove\
		ft_memset\
		ft_strsub\
		ft_strjoin\
		ft_strtrim\
		ft_strsplit\
		ft_wordcount\
		ft_lstnew\
		ft_lstdelone\
		ft_lstdel\
		ft_lstadd\
		ft_lstiter\
		ft_lstmap\
		ft_itoa_base\
		ft_strupcase\
		ft_isupper\
		ft_islower\
		ft_swap\
		ft_2d_malloc\
		ft_heightlen\
		ft_str2dcpy\
		ft_free2d\
		ft_free3d

HEADER = libft.h

FILES = $(addsuffix .c, $(SRCS))

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean

