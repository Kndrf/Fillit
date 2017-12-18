# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/27 18:58:49 by ghazette     #+#   ##    ##    #+#        #
#    Updated: 2017/12/07 17:43:11 by ghazette    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRCS =		check.c\
			cmp.c\
			cmp1.c\
			cmp2.c\
			cmp3.c\
			open.c\
			free.c\
			convert_buf.c\
			solve_func.c\
			init_l.c\
			init_line.c\
			init_square.c\
			init_stairs.c\
			init_triangle.c\
			shape_gen.c\
			solver.c\
			main.c\

HEADERS = 	libft/libft.h includes/fillit.h

LIBFT =		libft/libft.a

CFLAGS = 	-Wall -Werror -Wextra

OBJS = 	$(SRCS:%.c=%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

$(LIBFT) :
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
